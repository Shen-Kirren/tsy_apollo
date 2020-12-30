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

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/canbus/proto/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace devkit {

class Iecucontrolpower504 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Iecucontrolpower504();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_Speed', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|80]', 'physical_unit': 'km/h', 'precision': 0.1, 'type': 'double'}
  Iecucontrolpower504* set_iecu_power_speed(double iecu_power_speed);

  // config detail: {'bit': 40, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Power_Torque', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
  Iecucontrolpower504* set_iecu_power_torque(int iecu_power_torque);

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Acc_De_Control', 'offset': -100.0, 'order': 'intel', 'physical_range': '[-100|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
  Iecucontrolpower504* set_iecu_acc_de_control(int iecu_acc_de_control);

  // config detail: {'bit': 24, 'enum': {0: 'IECU_POWER_GEAR_PARK_CMD', 1: 'IECU_POWER_GEAR_DRIVE_CMD', 2: 'IECU_POWER_GEAR_NEUTRAL_CMD', 3: 'IECU_POWER_GEAR_REVERSE_CMD'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Power_Gear', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  Iecucontrolpower504* set_iecu_power_gear(Iecu_control_power_504::Iecu_power_gearType iecu_power_gear);

  // config detail: {'bit': 16, 'enum': {0: 'IECU_TORQUE_OR_SPEED_OR_ACC_POW_TORQUE', 1: 'IECU_TORQUE_OR_SPEED_OR_ACC_POW_SPEED', 2: 'IECU_TORQUE_OR_SPEED_OR_ACC_POW_ACC'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_torque_or_speed_or_Acc', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  Iecucontrolpower504* set_iecu_torque_or_speed_or_acc(Iecu_control_power_504::Iecu_torque_or_speed_or_accType iecu_torque_or_speed_or_acc);

  // config detail: {'bit': 8, 'enum': {0: 'IECU_TOTAL_OR_DISTRIBUTE_POW_TOTAL', 1: 'IECU_TOTAL_OR_DISTRIBUTE_POW_DISTRIBUTED'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_total_or_distribute', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  Iecucontrolpower504* set_iecu_total_or_distribute(Iecu_control_power_504::Iecu_total_or_distributeType iecu_total_or_distribute);

  // config detail: {'bit': 0, 'enum': {0: 'IECU_POWER_VALID_POW_DISABLE', 1: 'IECU_POWER_VALID_POW_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Power_Valid', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  Iecucontrolpower504* set_iecu_power_valid(Iecu_control_power_504::Iecu_power_validType iecu_power_valid);

 private:

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_Speed', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|80]', 'physical_unit': 'km/h', 'precision': 0.1, 'type': 'double'}
  void set_p_iecu_power_speed(uint8_t* data, double iecu_power_speed);

  // config detail: {'bit': 40, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Power_Torque', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
  void set_p_iecu_power_torque(uint8_t* data, int iecu_power_torque);

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Acc_De_Control', 'offset': -100.0, 'order': 'intel', 'physical_range': '[-100|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
  void set_p_iecu_acc_de_control(uint8_t* data, int iecu_acc_de_control);

  // config detail: {'bit': 24, 'enum': {0: 'IECU_POWER_GEAR_PARK_CMD', 1: 'IECU_POWER_GEAR_DRIVE_CMD', 2: 'IECU_POWER_GEAR_NEUTRAL_CMD', 3: 'IECU_POWER_GEAR_REVERSE_CMD'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Power_Gear', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  void set_p_iecu_power_gear(uint8_t* data, Iecu_control_power_504::Iecu_power_gearType iecu_power_gear);

  // config detail: {'bit': 16, 'enum': {0: 'IECU_TORQUE_OR_SPEED_OR_ACC_POW_TORQUE', 1: 'IECU_TORQUE_OR_SPEED_OR_ACC_POW_SPEED', 2: 'IECU_TORQUE_OR_SPEED_OR_ACC_POW_ACC'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_torque_or_speed_or_Acc', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  void set_p_iecu_torque_or_speed_or_acc(uint8_t* data, Iecu_control_power_504::Iecu_torque_or_speed_or_accType iecu_torque_or_speed_or_acc);

  // config detail: {'bit': 8, 'enum': {0: 'IECU_TOTAL_OR_DISTRIBUTE_POW_TOTAL', 1: 'IECU_TOTAL_OR_DISTRIBUTE_POW_DISTRIBUTED'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_total_or_distribute', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  void set_p_iecu_total_or_distribute(uint8_t* data, Iecu_control_power_504::Iecu_total_or_distributeType iecu_total_or_distribute);

  // config detail: {'bit': 0, 'enum': {0: 'IECU_POWER_VALID_POW_DISABLE', 1: 'IECU_POWER_VALID_POW_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Power_Valid', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  void set_p_iecu_power_valid(uint8_t* data, Iecu_control_power_504::Iecu_power_validType iecu_power_valid);

 private:
  double iecu_power_speed_;
  int iecu_power_torque_;
  int iecu_acc_de_control_;
  Iecu_control_power_504::Iecu_power_gearType iecu_power_gear_;
  Iecu_control_power_504::Iecu_torque_or_speed_or_accType iecu_torque_or_speed_or_acc_;
  Iecu_control_power_504::Iecu_total_or_distributeType iecu_total_or_distribute_;
  Iecu_control_power_504::Iecu_power_validType iecu_power_valid_;
};

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo


