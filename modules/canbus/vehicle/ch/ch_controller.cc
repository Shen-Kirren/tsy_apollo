/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/ch/ch_controller.h"

#include "modules/common/proto/vehicle_signal.pb.h"

//#include "cyber/common/log.h"
#include "modules/common/log.h"
#include "modules/canbus/vehicle/ch/ch_message_manager.h"
#include "modules/canbus/vehicle/vehicle_controller.h"
//#include "cyber/time/time.h"
#include "modules/common/time/time.h"
#include "modules/drivers/canbus/can_comm/can_sender.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

#include "modules/canbus/vehicle/ch/ch_controller.h"
#include "modules/common/log.h"
#include "modules/canbus/vehicle/ch/ch_message_manager.h"
#include "modules/canbus/vehicle/vehicle_controller.h"
#include "modules/common/proto/vehicle_signal.pb.h"
#include "modules/common/time/time.h"
#include "modules/drivers/canbus/can_comm/can_sender.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::ProtocolData;
using ::apollo::common::ErrorCode;
using ::apollo::control::ControlCommand;

namespace {

const int32_t kMaxFailAttempt = 10;
const int32_t CHECK_RESPONSE_STEER_UNIT_FLAG = 1;
const int32_t CHECK_RESPONSE_SPEED_UNIT_FLAG = 2;
}

ErrorCode ChController::Init(
	const VehicleParameter& params,
	CanSender<::apollo::canbus::ChassisDetail> *const can_sender,
    MessageManager<::apollo::canbus::ChassisDetail> *const message_manager) {
  if (is_initialized_) {
    AINFO << "ChController has already been initiated.";
    return ErrorCode::CANBUS_ERROR;
  }

    vehicle_params_.CopyFrom(
      common::VehicleConfigHelper::instance()->GetConfig().vehicle_param());
      


  params_.CopyFrom(params);
  if (!params_.has_driving_mode()) {
    AERROR << "Vehicle conf pb not set driving_mode.";
    return ErrorCode::CANBUS_ERROR;
  }

  if (can_sender == nullptr) {
    return ErrorCode::CANBUS_ERROR;
  }
  can_sender_ = can_sender;

  if (message_manager == nullptr) {
    AERROR << "protocol manager is null.";
    return ErrorCode::CANBUS_ERROR;
  }
  message_manager_ = message_manager;

  // sender part
  iecu_control_distributed_505_ = dynamic_cast<Iecucontroldistributed505*>
          (message_manager_->GetMutableProtocolDataById(Iecucontroldistributed505::ID));
  if (iecu_control_distributed_505_ == nullptr) {
     AERROR << "Iecucontroldistributed505 does not exist in the ChMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }
  AINFO << "Iecucontroldistributed505 connect OK!";

  iecu_control_flag_501_ = dynamic_cast<Iecucontrolflag501*>
          (message_manager_->GetMutableProtocolDataById(Iecucontrolflag501::ID));
  if (iecu_control_flag_501_ == nullptr) {
     AERROR << "Iecucontrolflag501 does not exist in the ChMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

  iecu_control_ibc_503_ = dynamic_cast<Iecucontrolibc503*>
          (message_manager_->GetMutableProtocolDataById(Iecucontrolibc503::ID));
  if (iecu_control_ibc_503_ == nullptr) {
     AERROR << "Iecucontrolibc503 does not exist in the ChMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

  iecu_control_power_504_ = dynamic_cast<Iecucontrolpower504*>
          (message_manager_->GetMutableProtocolDataById(Iecucontrolpower504::ID));
  if (iecu_control_power_504_ == nullptr) {
     AERROR << "Iecucontrolpower504 does not exist in the ChMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

  iecu_control_steering_502_ = dynamic_cast<Iecucontrolsteering502*>
          (message_manager_->GetMutableProtocolDataById(Iecucontrolsteering502::ID));
  if (iecu_control_steering_502_ == nullptr) {
     AERROR << "Iecucontrolsteering502 does not exist in the ChMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

//修改false 为true
  can_sender_->AddMessage(Iecucontroldistributed505::ID, iecu_control_distributed_505_, false);
  can_sender_->AddMessage(Iecucontrolflag501::ID, iecu_control_flag_501_, false);
  can_sender_->AddMessage(Iecucontrolibc503::ID, iecu_control_ibc_503_, false);
  can_sender_->AddMessage(Iecucontrolpower504::ID, iecu_control_power_504_, false);
  can_sender_->AddMessage(Iecucontrolsteering502::ID, iecu_control_steering_502_, false);

  // need sleep to ensure all messages received
  AINFO << "ChController is initialized.";

  is_initialized_ = true;
  return ErrorCode::OK;
}

ChController::~ChController() {}

bool ChController::Start() {
  if (!is_initialized_) {
    AERROR << "ChController has NOT been initiated.";
    return false;
  }
  const auto& update_func = [this] { SecurityDogThreadFunc(); };
  thread_.reset(new std::thread(update_func));

  return true;
}

void ChController::Stop() {
  if (!is_initialized_) {
    AERROR << "ChController stops or starts improperly!";
    return;
  }

  if (thread_ != nullptr && thread_->joinable()) {
    thread_->join();
    thread_.reset();
    AINFO << "ChController stopped.";
  }
}

Chassis ChController::chassis() {
  chassis_.Clear();

  ChassisDetail chassis_detail;
  message_manager_->GetSensorData(&chassis_detail);

  // 21, 22, previously 1, 2
  if (driving_mode() == Chassis::EMERGENCY_MODE) {
    set_chassis_error_code(Chassis::NO_ERROR);
  }
  //手动强制将底盘的信息改为AUTO模式
  //chassis_.set_driving_mode(driving_mode());
  chassis_.set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
  chassis_.set_error_code(chassis_error_code());

  // 3
  chassis_.set_engine_started(true);
  //AINFO << "ENGINE START!";
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  */
 if (!chassis_detail.has_ch()) {
    AERROR << "NO TSY chassis information!";
    return chassis_;
  }
  //TSY ch = chassis_detail.ch();
  //4 Ch:ch 没有发动机转速信号
  //5 wheel spd 0x305或者0x10-0x40
  if (chassis_detail.ch().has_vcu_vehicle_status_3_305()) {
    if (chassis_detail.ch().vcu_vehicle_status_3_305().has_rpm_fl_rpt()) {
      chassis_.mutable_wheel_speed()->set_wheel_spd_fl(
          chassis_detail.ch().vcu_vehicle_status_3_305().rpm_fl_rpt());
    }
    if (chassis_detail.ch().vcu_vehicle_status_3_305().has_rpm_fr_rpt()) {
      chassis_.mutable_wheel_speed()->set_wheel_spd_fr(
          chassis_detail.ch().vcu_vehicle_status_3_305().rpm_fr_rpt());
    }
    if (chassis_detail.ch().vcu_vehicle_status_3_305().has_rpm_rl_rpt()) {
      chassis_.mutable_wheel_speed()->set_wheel_spd_rl(
          chassis_detail.ch().vcu_vehicle_status_3_305().rpm_rl_rpt());
    }
    if (chassis_detail.ch().vcu_vehicle_status_3_305().has_rpm_rr_rpt()) {
      chassis_.mutable_wheel_speed()->set_wheel_spd_rr(
          chassis_detail.ch().vcu_vehicle_status_3_305().rpm_rr_rpt());
    }
  }
  //6 speed_mps 这个是米每秒的车速  0x304
  if (chassis_detail.ch().has_vcu_vehicle_status_2_304() && chassis_detail.ch().vcu_vehicle_status_2_304().has_vehicle_speed()) {
    chassis_.set_speed_mps(
        static_cast<float>(chassis_detail.ch().vcu_vehicle_status_2_304().vehicle_speed()));
  } else {
    chassis_.set_speed_mps(0);
  }
  // 7 no odometer
  // chassis_.set_odometer_m(0);
  // 8 no fuel. do not set;
  // chassis_.set_fuel_range_m(0);
  // 9 throttle 0x304
  if (chassis_detail.ch().has_vcu_vehicle_status_2_304() &&
      chassis_detail.ch().vcu_vehicle_status_2_304().has_throttle_rpt()) {
    chassis_.set_throttle_percentage(static_cast<float>(
        chassis_detail.ch().vcu_vehicle_status_2_304().throttle_rpt()));
  } else {
    chassis_.set_throttle_percentage(0);
  }
  // 10 brake 0x304
  if (chassis_detail.ch().has_vcu_vehicle_status_2_304() &&
      chassis_detail.ch().vcu_vehicle_status_2_304().has_vehicle_brake_pressure()) {
    chassis_.set_brake_percentage(static_cast<float>(
        chassis_detail.ch().vcu_vehicle_status_2_304().vehicle_brake_pressure()));
  } else {
    chassis_.set_brake_percentage(0);
  }
  /*  下面是原来用0x142的传感器反馈的，这里为了测试就改用0x304了
  if (ch.has_dbsf_status_142() &&
      ch.dbsf_status_142().has_dbsf_hp_pressure()) {
    chassis_.set_brake_percentage(static_cast<float>(
        ch.dbsf_status_142().has_dbsf_hp_pressure()));
  } else {
    chassis_.set_brake_percentage(0);
  }
  */
  // 23, previously 11 gear 0x303中定义挡位反馈
  if (chassis_detail.ch().has_vcu_vehicle_status_1_303() &&
      chassis_detail.ch().vcu_vehicle_status_1_303().has_gear_rpt()) {
    Chassis::GearPosition gear_pos = Chassis::GEAR_INVALID;

    if (chassis_detail.ch().vcu_vehicle_status_1_303().gear_rpt() ==
        Vcu_vehicle_status_1_303::GEAR_RPT_INVALID) {
      gear_pos = Chassis::GEAR_INVALID;
    }
    if (chassis_detail.ch().vcu_vehicle_status_1_303().gear_rpt() ==
        Vcu_vehicle_status_1_303::GEAR_RPT_NEUTRAL) {
      gear_pos = Chassis::GEAR_NEUTRAL;
    }
    if (chassis_detail.ch().vcu_vehicle_status_1_303().gear_rpt() ==
        Vcu_vehicle_status_1_303::GEAR_RPT_REVERSE) {
      gear_pos = Chassis::GEAR_REVERSE;
    }
    if (chassis_detail.ch().vcu_vehicle_status_1_303().gear_rpt() ==
        Vcu_vehicle_status_1_303::GEAR_RPT_DRIVE) {
      gear_pos = Chassis::GEAR_DRIVE;
    }
    if (chassis_detail.ch().vcu_vehicle_status_1_303().gear_rpt() ==
        Vcu_vehicle_status_1_303::GEAR_RPT_PARKING) {
      gear_pos = Chassis::GEAR_PARKING;
    }
    chassis_.set_gear_location(gear_pos);
  } else {
    chassis_.set_gear_location(Chassis::GEAR_NONE);
  }
  // 12 steering 0x304
  if (chassis_detail.ch().has_vcu_vehicle_status_2_304() &&
      chassis_detail.ch().vcu_vehicle_status_2_304().has_f_tire_angle()) {
    chassis_.set_steering_percentage(static_cast<float>(
        chassis_detail.ch().vcu_vehicle_status_2_304().f_tire_angle() *
        100.0 / vehicle_params_.max_steer_angle() * M_PI / 180));
  } else {
    chassis_.set_steering_percentage(0);
  }
  // 13 parking brake
  if (chassis_detail.ch().has_vcu_vehicle_status_1_303() &&
      chassis_detail.ch().vcu_vehicle_status_1_303().has_epb_rpt()) {
    if (chassis_detail.ch().vcu_vehicle_status_1_303().epb_rpt() ==
        Vcu_vehicle_status_1_303::EPB_RPT_EPB_ON) {
      chassis_.set_parking_brake(true);
    } else {
      chassis_.set_parking_brake(false);
    }
  } else {
    chassis_.set_parking_brake(false);
  }


  return chassis_;
}

void ChController::Emergency() {
  set_driving_mode(Chassis::EMERGENCY_MODE);
  ResetProtocol();
}

ErrorCode ChController::EnableAutoMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE) {
    AINFO << "already in COMPLETE_AUTO_DRIVE mode";
    return ErrorCode::OK;
  }
  //这里为什么会有个return？
  //return ErrorCode::OK;
  // set enable
  iecu_control_flag_501_->set_iecu_control_request_flag(
      Iecu_control_flag_501::IECU_CONTROL_REQUEST_FLAG_IECU_ENABLE);
      AINFO << "enable AUTO mode OK.";
  iecu_control_steering_502_->set_iecu_steering_valid(
      Iecu_control_steering_502::IECU_STEERING_VALID_STR_ENABLE);
  iecu_control_ibc_503_->set_iecu_ibc_valid(
      Iecu_control_ibc_503::IECU_IBC_VALID_BRK_ENABLE);
  iecu_control_power_504_->set_iecu_power_valid(
      Iecu_control_power_504::IECU_POWER_VALID_POW_ENABLE);

  can_sender_->Update();
  const int32_t flag =
      CHECK_RESPONSE_STEER_UNIT_FLAG | CHECK_RESPONSE_SPEED_UNIT_FLAG;
  if (!CheckResponse(flag, true)) {
    AERROR << "Failed to switch to COMPLETE_AUTO_DRIVE mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
  AINFO << "Switch to COMPLETE_AUTO_DRIVE mode ok.";

  return ErrorCode::OK;
}

ErrorCode ChController::DisableAutoMode() {
  ResetProtocol();
  can_sender_->Update();
  //set_driving_mode(Chassis::COMPLETE_MANUAL);
  set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
  set_chassis_error_code(Chassis::NO_ERROR);
  AINFO << "Switch to COMPLETE_MANUAL ok.";
  return ErrorCode::OK;
}

ErrorCode ChController::EnableSteeringOnlyMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::AUTO_STEER_ONLY) {
    set_driving_mode(Chassis::AUTO_STEER_ONLY);
    AINFO << "Already in AUTO_STEER_ONLY mode.";
    return ErrorCode::OK;
  }
  AFATAL << "SteerOnlyMode is not supported in this car!";
  return ErrorCode::CANBUS_ERROR;
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  brake_60_->set_disable();
  throttle_62_->set_disable();
  steering_64_->set_enable();

  can_sender_->Update();
  if (!CheckResponse(CHECK_RESPONSE_STEER_UNIT_FLAG, true)) {
    AERROR << "Failed to switch to AUTO_STEER_ONLY mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::AUTO_STEER_ONLY);
  AINFO << "Switch to AUTO_STEER_ONLY mode ok.";
  return ErrorCode::OK;
  */
}

ErrorCode ChController::EnableSpeedOnlyMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::AUTO_SPEED_ONLY) {
    set_driving_mode(Chassis::AUTO_SPEED_ONLY);
    AINFO << "Already in AUTO_SPEED_ONLY mode";
    return ErrorCode::OK;
  }
  AFATAL << "SpeedOnlyMode is not supported in this car!";
  return ErrorCode::CANBUS_ERROR;
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  brake_60_->set_enable();
  throttle_62_->set_enable();
  steering_64_->set_disable();

  can_sender_->Update();
  if (!CheckResponse(CHECK_RESPONSE_SPEED_UNIT_FLAG, true)) {
    AERROR << "Failed to switch to AUTO_SPEED_ONLY mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::AUTO_SPEED_ONLY);
  AINFO << "Switch to AUTO_SPEED_ONLY mode ok.";
  return ErrorCode::OK;
  */
}

// NEUTRAL, REVERSE, DRIVE
void ChController::Gear(Chassis::GearPosition gear_position) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "This drive mode no need to set gear.";
    return;
  }
  // ADD YOUR OWN CAR CHASSIS OPERATION
  switch (gear_position) {
    case Chassis::GEAR_NEUTRAL: {
      iecu_control_power_504_->set_iecu_power_gear(Iecu_control_power_504::IECU_POWER_GEAR_NEUTRAL_CMD);
      break;
    }
    case Chassis::GEAR_REVERSE: {
      iecu_control_power_504_->set_iecu_power_gear(Iecu_control_power_504::IECU_POWER_GEAR_REVERSE_CMD);
      break;
    }
    case Chassis::GEAR_DRIVE: {
      iecu_control_power_504_->set_iecu_power_gear(Iecu_control_power_504::IECU_POWER_GEAR_DRIVE_CMD);
      break;
    }
    case Chassis::GEAR_PARKING: {
      iecu_control_power_504_->set_iecu_power_gear(Iecu_control_power_504::IECU_POWER_GEAR_PARK_CMD);
      break;
    }
    /*
    case Chassis::GEAR_LOW: {
      gear_66_->set_gear_low();
      break;
    }
    并没有设计低速档，所以这段不用。
    */
    case Chassis::GEAR_NONE: {
      iecu_control_power_504_->set_iecu_power_gear(Iecu_control_power_504::IECU_POWER_GEAR_NEUTRAL_CMD);
      break;
    }
    case Chassis::GEAR_INVALID: {
      AERROR << "Gear command is invalid!";
      iecu_control_power_504_->set_iecu_power_gear(Iecu_control_power_504::IECU_POWER_GEAR_NEUTRAL_CMD);
      break;
    }
    default: {
      iecu_control_power_504_->set_iecu_power_gear(Iecu_control_power_504::IECU_POWER_GEAR_NEUTRAL_CMD);
      break;
    }
  }
}

// brake with new acceleration
// acceleration:0.00~99.99, unit:
// acceleration:0.0 ~ 7.0, unit:m/s^2
// acceleration_spd:60 ~ 100, suggest: 90
// -> pedal
void ChController::Brake(double pedal) {
  // double real_value = params_.max_acc() * acceleration / 100;
  // TODO(All) :  Update brake value based on mode
  //屏蔽掉原有driving_mode，都是左值，无法直接赋值
  //driving_mode() = Chassis::COMPLETE_AUTO_DRIVE;

  // if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
  //     driving_mode() != Chassis::AUTO_SPEED_ONLY) {
  //   AINFO << "The current drive mode does not need to set brake pedal.";
  //   return;
  // }
  iecu_control_ibc_503_->set_iecu_brakepressure_cmd(pedal);
}

// drive with old acceleration
// gas:0.00~99.99 unit:
void ChController::Throttle(double pedal) {
  //屏蔽掉原有driving_mode，都是左值，无法直接赋值
  //driving_mode() = Chassis::COMPLETE_AUTO_DRIVE;

  // if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
  //     driving_mode() != Chassis::AUTO_SPEED_ONLY) {
  //   AINFO << "The current drive mode does not need to set throttle pedal.";
  //   return;
  // }
  iecu_control_power_504_->set_iecu_total_or_distribute(
      Iecu_control_power_504::IECU_TOTAL_OR_DISTRIBUTE_POW_TOTAL);
  iecu_control_power_504_->set_iecu_torque_or_speed_or_acc(
      Iecu_control_power_504::IECU_TORQUE_OR_SPEED_OR_ACC_POW_TORQUE);
  iecu_control_power_504_->set_iecu_power_torque(pedal);
}

// confirm the car is driven by acceleration command or throttle/brake pedal
// drive with acceleration/deceleration
// acc:-7.0 ~ 5.0, unit:m/s^2
void ChController::Acceleration(double acc) {
  // if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE ||
  //     driving_mode() != Chassis::AUTO_SPEED_ONLY) {
  //   AINFO << "The current drive mode does not need to set acceleration.";
  //   return;
  // }
  iecu_control_power_504_->set_iecu_total_or_distribute(
      Iecu_control_power_504::IECU_TOTAL_OR_DISTRIBUTE_POW_TOTAL);
  iecu_control_power_504_->set_iecu_torque_or_speed_or_acc(
      Iecu_control_power_504::IECU_TORQUE_OR_SPEED_OR_ACC_POW_ACC);
  iecu_control_power_504_->set_iecu_acc_de_control(acc);
}

// ch default, -470 ~ 470, left:+, right:-
// need to be compatible with control module, so reverse
// steering with old angle speed
// angle:-99.99~0.00~99.99, unit:, left:-, right:+
void ChController::Steer(double angle) {
  //屏蔽掉原有driving_mode
  //driving_mode() = Chassis::COMPLETE_AUTO_DRIVE;

  // if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
  //     driving_mode() != Chassis::AUTO_STEER_ONLY) {
  //   AINFO << "The current driving mode does not need to set steer.";
  //   return;
  // }
  const double real_angle = vehicle_params_.max_steer_angle() * angle / 100.0;
  // reverse sign
  iecu_control_steering_502_->set_iecu_ftire_angle_cmd(real_angle);
  iecu_control_steering_502_->set_iecu_ftire_speed_cmd(200);
}

// steering with new angle speed
// angle:-99.99~0.00~99.99, unit:, left:-, right:+
// angle_spd:0.00~99.99, unit:deg/s
void ChController::Steer(double angle, double angle_spd) {
  //屏蔽掉原有driving_mode
  //driving_mode() = Chassis::COMPLETE_AUTO_DRIVE;
  
  // if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
  //     driving_mode() != Chassis::AUTO_STEER_ONLY) {
  //   AINFO << "The current driving mode does not need to set steer.";
  //   return;
  // }
  const double real_angle = vehicle_params_.max_steer_angle() * angle / 100.0;
  const double real_angle_spd = 250*angle_spd/100;
  // reverse sign
  iecu_control_steering_502_->set_iecu_ftire_angle_cmd(real_angle);
  iecu_control_steering_502_->set_iecu_ftire_speed_cmd(real_angle_spd);
}

void ChController::SetEpbBreak(const ControlCommand& command) {
  if (command.parking_brake()) {
    // None
  } else {
    // None
  }
}

void ChController::SetBeam(const ControlCommand& command) {
  if (command.signal().high_beam()) {
    // None
  } else if (command.signal().low_beam()) {
    // None
  } else {
    // None
  }
}

void ChController::SetHorn(const ControlCommand& command) {
  if (command.signal().horn()) {
    // None
  } else {
    // None
  }
}

void ChController::SetTurningSignal(const ControlCommand& command) {
  // Set Turn Signal
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  auto signal = command.signal().turn_signal();
  if (signal == Signal::TURN_LEFT) {
    turnsignal_68_->set_turn_left();
  } else if (signal == Signal::TURN_RIGHT) {
    turnsignal_68_->set_turn_right();
  } else {
    turnsignal_68_->set_turn_none();
  }
  */
}

void ChController::ResetProtocol() {
  message_manager_->ResetSendMessages();
}

bool ChController::CheckChassisError() {
  ChassisDetail chassis_detail;
  message_manager_->GetSensorData(&chassis_detail);
  if (!chassis_detail.has_ch()) {
    AERROR_EVERY(100) << "ChassisDetail has no ch vehicle info."
                      << chassis_detail.DebugString();
    return false;
  }

  Ch ch = chassis_detail.ch();

  // steer fault
  if (ch.has_vcu_vehicle_diagnosis_301()) {
    if (Vcu_vehicle_diagnosis_301::FSTEERING_STATE_FSTR_FAULT ==
        ch.vcu_vehicle_diagnosis_301().fsteering_state()) {
      return true;
    }
  }
  // drive fault
  if (ch.has_vcu_vehicle_diagnosis_301()) {
    if (Vcu_vehicle_diagnosis_301::FLMOTOR_STATE_FL_FAULT ==
       ch.vcu_vehicle_diagnosis_301().flmotor_state()) {
      return true;
    }
    if (Vcu_vehicle_diagnosis_301::FRMOTOR_STATE_FR_FAULT ==
       ch.vcu_vehicle_diagnosis_301().frmotor_state()) {
      return true;
    }
    if (Vcu_vehicle_diagnosis_301::RLMOTOR_STATE_RL_FAULT ==
       ch.vcu_vehicle_diagnosis_301().rlmotor_state()) {
      return true;
    }
    if (Vcu_vehicle_diagnosis_301::RRMOTOR_STATE_RR_FAULT ==
       ch.vcu_vehicle_diagnosis_301().rrmotor_state()) {
      return true;
    }
  }
  // brake fault
  if (ch.has_vcu_vehicle_diagnosis_301()) {
    if (Vcu_vehicle_diagnosis_301::DBSF_STATE_DBSF_FAULT ==
        ch.vcu_vehicle_diagnosis_301().dbsf_state()) {
      return true;
    }
  }
  // gear fault
  /*
  挡位并没有错误码，也不知道酷黑是哪里来的这个信号。
  */
  // park fault
  if (ch.has_vcu_vehicle_diagnosis_301()) {
    if (Vcu_vehicle_diagnosis_301::EPB_STATE_EPB_FAULT ==
        ch.vcu_vehicle_diagnosis_301().epb_state()) {
      return true;
    }
  }
  return false;
}

void ChController::SecurityDogThreadFunc() {
  int32_t vertical_ctrl_fail = 0;
  int32_t horizontal_ctrl_fail = 0;

  if (can_sender_ == nullptr) {
    AERROR << "Failed to run SecurityDogThreadFunc() because can_sender_ is "
              "nullptr.";
    return;
  }
  while (!can_sender_->IsRunning()) {
    std::this_thread::yield();
  }

  std::chrono::duration<double, std::micro> default_period{50000};
  int64_t start = 0;
  int64_t end = 0;
  while (can_sender_->IsRunning()) {
    //start = ::apollo::cyber::Time::Now().ToMicrosecond();
    //start = absl::ToUnixMicros(::apollo::common::time::Clock::Now());
    start = ::apollo::common::time::AsInt64<::apollo::common::time::micros>(
        ::apollo::common::time::Clock::Now());
    const Chassis::DrivingMode mode = driving_mode();
    bool emergency_mode = false;

    // 1. horizontal control check
    if ((mode == Chassis::COMPLETE_AUTO_DRIVE ||
         mode == Chassis::AUTO_STEER_ONLY) &&
        CheckResponse(CHECK_RESPONSE_STEER_UNIT_FLAG, false) == false) {
      ++horizontal_ctrl_fail;
      if (horizontal_ctrl_fail >= kMaxFailAttempt) {
        emergency_mode = true;
        set_chassis_error_code(Chassis::MANUAL_INTERVENTION);
      }
    } else {
      horizontal_ctrl_fail = 0;
    }

    // 2. vertical control check
    if ((mode == Chassis::COMPLETE_AUTO_DRIVE ||
         mode == Chassis::AUTO_SPEED_ONLY) &&
        !CheckResponse(CHECK_RESPONSE_SPEED_UNIT_FLAG, false)) {
      ++vertical_ctrl_fail;
      if (vertical_ctrl_fail >= kMaxFailAttempt) {
        emergency_mode = true;
        set_chassis_error_code(Chassis::MANUAL_INTERVENTION);
      }
    } else {
      vertical_ctrl_fail = 0;
    }
    if (CheckChassisError()) {
      set_chassis_error_code(Chassis::CHASSIS_ERROR);
      emergency_mode = true;
    }

    if (emergency_mode && mode != Chassis::EMERGENCY_MODE) {
      set_driving_mode(Chassis::EMERGENCY_MODE);
      message_manager_->ResetSendMessages();
    }
    //end = ::apollo::cyber::Time::Now().ToMicrosecond();
    //end = absl::ToUnixMicros(::apollo::common::time::Clock::Now());
    end = ::apollo::common::time::AsInt64<::apollo::common::time::micros>(
        ::apollo::common::time::Clock::Now());
    std::chrono::duration<double, std::micro> elapsed{end - start};
    if (elapsed < default_period) {
      std::this_thread::sleep_for(default_period - elapsed);
    } else {
      AERROR
          << "Too much time consumption in ChController looping process:"
          << elapsed.count();
    }
  }
}

bool ChController::CheckResponse(const int32_t flags, bool need_wait) {
  //int32_t retry_num = 20;
  //上升沿触发时间，参考adaption说明修改
  int32_t retry_num = 20;
  ChassisDetail chassis_detail;
  bool is_eps_online = false;
  bool is_vcu_online = false;
  bool is_esp_online = false;

  do {
    if (message_manager_->GetSensorData(&chassis_detail) != ErrorCode::OK) {
      AERROR_EVERY(100) << "get chassis detail failed.";
      return false;
    }
    bool check_ok = true;
    if (flags & CHECK_RESPONSE_STEER_UNIT_FLAG) {
      is_eps_online = chassis_detail.has_check_response() &&
                      chassis_detail.check_response().has_is_eps_online() &&
                      chassis_detail.check_response().is_eps_online();
      check_ok = check_ok && is_eps_online;
    }

    if (flags & CHECK_RESPONSE_SPEED_UNIT_FLAG) {
      is_vcu_online = chassis_detail.has_check_response() &&
                      chassis_detail.check_response().has_is_vcu_online() &&
                      chassis_detail.check_response().is_vcu_online();
      is_esp_online = chassis_detail.has_check_response() &&
                      chassis_detail.check_response().has_is_esp_online() &&
                      chassis_detail.check_response().is_esp_online();
      check_ok = check_ok && is_vcu_online && is_esp_online;
    }
    if (check_ok) {
      return true;
    } else {
      AINFO << "Need to check response again.";
    }
    if (need_wait) {
      --retry_num;
      std::this_thread::sleep_for(
          std::chrono::duration<double, std::milli>(20));
          //std::chrono::duration<double, std::milli>(2000));
    }
  } while (need_wait && retry_num);

  AINFO << "check_response fail: is_eps_online:" << is_eps_online
        << ", is_vcu_online:" << is_vcu_online
        << ", is_esp_online:" << is_esp_online;
        
  return false;
}

void ChController::set_chassis_error_mask(const int32_t mask) {
  std::lock_guard<std::mutex> lock(chassis_mask_mutex_);
  chassis_error_mask_ = mask;
}

int32_t ChController::chassis_error_mask() {
  std::lock_guard<std::mutex> lock(chassis_mask_mutex_);
  return chassis_error_mask_;
}

Chassis::ErrorCode ChController::chassis_error_code() {
  std::lock_guard<std::mutex> lock(chassis_error_code_mutex_);
  return chassis_error_code_;
}

void ChController::set_chassis_error_code(
    const Chassis::ErrorCode& error_code) {
  std::lock_guard<std::mutex> lock(chassis_error_code_mutex_);
  chassis_error_code_ = error_code;
}

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
