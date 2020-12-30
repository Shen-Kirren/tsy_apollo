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

class Mcurrdrivemotorfeedbackmsg90 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Mcurrdrivemotorfeedbackmsg90();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 43, 'is_signed_var': False, 'len': 21, 'name': 'RR_Reserved_1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int rr_reserved_1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 41, 'enum': {0: 'RR_MCU_MOTOR_ERROR_GRADE_NORMAL', 1: 'RR_MCU_MOTOR_ERROR_GRADE_SLIGHT_FAULT', 2: 'RR_MCU_MOTOR_ERROR_GRADE_SERIOUS_FAULT', 3: 'RR_MCU_MOTOR_ERROR_GRADE_BREAK_DOWN'}, 'is_signed_var': False, 'len': 2, 'name': 'RR_MCU_Motor_Error_Grade', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Mcurr_drive_motor_feedback_msg_90::Rr_mcu_motor_error_gradeType rr_mcu_motor_error_grade(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 40, 'is_signed_var': False, 'len': 1, 'name': 'RR_Energy_Recovery_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool rr_energy_recovery_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'RR_ControlTemp', 'offset': -50.0, 'order': 'intel', 'physical_range': '[-50|205]', 'physical_unit': 'DU', 'precision': 1.0, 'type': 'int'}
  int rr_controltemp(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'RR_Idc', 'offset': -1000.0, 'order': 'intel', 'physical_range': '[-1000|5553.5]', 'physical_unit': 'A', 'precision': 0.1, 'type': 'double'}
  double rr_idc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'RR_Udc', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|6553.5]', 'physical_unit': 'V', 'precision': 0.1, 'type': 'double'}
  double rr_udc(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo


