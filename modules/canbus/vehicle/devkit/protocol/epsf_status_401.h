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

class Epsfstatus401 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Epsfstatus401();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 56, 'is_signed_var': False, 'len': 8, 'name': 'EPSF_Check_Sum', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int epsf_check_sum(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 8, 'name': 'EPSF_Reserved2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int epsf_reserved2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 40, 'is_signed_var': False, 'len': 8, 'name': 'EPSF_Angle_In_Middle_Calib', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int epsf_angle_in_middle_calib(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'Low_EPSF_Angle', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
  int low_epsf_angle(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 24, 'is_signed_var': False, 'len': 8, 'name': 'High_EPSF_Angle', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
  int high_epsf_angle(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'EPSF_Reserved1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int epsf_reserved1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'EPSF_Steering_Wheel_Torque_Value', 'offset': -12.8, 'order': 'intel', 'physical_range': '[-12.7|12.6]', 'physical_unit': 'Nm', 'precision': 0.1, 'type': 'double'}
  double epsf_steering_wheel_torque_value(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'EPSF_Work_Mode_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int epsf_work_mode_status(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo


