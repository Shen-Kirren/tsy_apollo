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

#include "modules/canbus/vehicle/ch/protocol/mcufl_drive_motor_feedback_msg_60.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

Mcufldrivemotorfeedbackmsg60::Mcufldrivemotorfeedbackmsg60() {}
const int32_t Mcufldrivemotorfeedbackmsg60::ID = 0x60;

void Mcufldrivemotorfeedbackmsg60::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_ch()->mutable_mcufl_drive_motor_feedback_msg_60()->set_fl_reserved_1(fl_reserved_1(bytes, length));
  chassis->mutable_ch()->mutable_mcufl_drive_motor_feedback_msg_60()->set_fl_mcu_motor_error_grade(fl_mcu_motor_error_grade(bytes, length));
  chassis->mutable_ch()->mutable_mcufl_drive_motor_feedback_msg_60()->set_fl_energy_recovery_state(fl_energy_recovery_state(bytes, length));
  chassis->mutable_ch()->mutable_mcufl_drive_motor_feedback_msg_60()->set_fl_controltemp(fl_controltemp(bytes, length));
  chassis->mutable_ch()->mutable_mcufl_drive_motor_feedback_msg_60()->set_fl_idc(fl_idc(bytes, length));
  chassis->mutable_ch()->mutable_mcufl_drive_motor_feedback_msg_60()->set_fl_udc(fl_udc(bytes, length));
}

// config detail: {'bit': 43, 'is_signed_var': False, 'len': 21, 'name': 'fl_reserved_1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Mcufldrivemotorfeedbackmsg60::fl_reserved_1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 5);
  t = t2.get_byte(3, 5);
  x <<= 5;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 41, 'enum': {0: 'FL_MCU_MOTOR_ERROR_GRADE_NORMAL', 1: 'FL_MCU_MOTOR_ERROR_GRADE_SLIGHT_FAULT', 2: 'FL_MCU_MOTOR_ERROR_GRADE_SERIOUS_FAULT', 3: 'FL_MCU_MOTOR_ERROR_GRADE_BREAK_DOWN'}, 'is_signed_var': False, 'len': 2, 'name': 'fl_mcu_motor_error_grade', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Mcufl_drive_motor_feedback_msg_60::Fl_mcu_motor_error_gradeType Mcufldrivemotorfeedbackmsg60::fl_mcu_motor_error_grade(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 2);

  Mcufl_drive_motor_feedback_msg_60::Fl_mcu_motor_error_gradeType ret =  static_cast<Mcufl_drive_motor_feedback_msg_60::Fl_mcu_motor_error_gradeType>(x);
  return ret;
}

// config detail: {'bit': 40, 'is_signed_var': False, 'len': 1, 'name': 'fl_energy_recovery_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Mcufldrivemotorfeedbackmsg60::fl_energy_recovery_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'fl_controltemp', 'offset': -50.0, 'order': 'intel', 'physical_range': '[-50|205]', 'physical_unit': 'DU', 'precision': 1.0, 'type': 'int'}
int Mcufldrivemotorfeedbackmsg60::fl_controltemp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  int ret = x + -50.000000;
  return ret;
}

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'fl_idc', 'offset': -1000.0, 'order': 'intel', 'physical_range': '[-1000|5553.5]', 'physical_unit': 'A', 'precision': 0.1, 'type': 'double'}
double Mcufldrivemotorfeedbackmsg60::fl_idc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000 + -1000.000000;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'fl_udc', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|6553.5]', 'physical_unit': 'V', 'precision': 0.1, 'type': 'double'}
double Mcufldrivemotorfeedbackmsg60::fl_udc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000;
  return ret;
}
}  // namespace ch
}  // namespace canbus
}  // namespace apollo
