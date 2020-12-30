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

#include "modules/canbus/vehicle/devkit/protocol/epsf_status_401.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace devkit {

using ::apollo::drivers::canbus::Byte;

Epsfstatus401::Epsfstatus401() {}
const int32_t Epsfstatus401::ID = 0x401;

void Epsfstatus401::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_devkit()->mutable_epsf_status_401()->set_epsf_check_sum(epsf_check_sum(bytes, length));
  chassis->mutable_devkit()->mutable_epsf_status_401()->set_epsf_reserved2(epsf_reserved2(bytes, length));
  chassis->mutable_devkit()->mutable_epsf_status_401()->set_epsf_angle_in_middle_calib(epsf_angle_in_middle_calib(bytes, length));
  chassis->mutable_devkit()->mutable_epsf_status_401()->set_low_epsf_angle(low_epsf_angle(bytes, length));
  chassis->mutable_devkit()->mutable_epsf_status_401()->set_high_epsf_angle(high_epsf_angle(bytes, length));
  chassis->mutable_devkit()->mutable_epsf_status_401()->set_epsf_reserved1(epsf_reserved1(bytes, length));
  chassis->mutable_devkit()->mutable_epsf_status_401()->set_epsf_steering_wheel_torque_value(epsf_steering_wheel_torque_value(bytes, length));
  chassis->mutable_devkit()->mutable_epsf_status_401()->set_epsf_work_mode_status(epsf_work_mode_status(bytes, length));
  //tsy_controller.cc中CheckReponse中要求的代码
  chassis->mutable_check_response()->set_is_eps_online(
      true);
}

// config detail: {'bit': 56, 'is_signed_var': False, 'len': 8, 'name': 'epsf_check_sum', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Epsfstatus401::epsf_check_sum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 8, 'name': 'epsf_reserved2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Epsfstatus401::epsf_reserved2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 40, 'is_signed_var': False, 'len': 8, 'name': 'epsf_angle_in_middle_calib', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Epsfstatus401::epsf_angle_in_middle_calib(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'low_epsf_angle', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
int Epsfstatus401::low_epsf_angle(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 24, 'is_signed_var': False, 'len': 8, 'name': 'high_epsf_angle', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
int Epsfstatus401::high_epsf_angle(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'epsf_reserved1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Epsfstatus401::epsf_reserved1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'epsf_steering_wheel_torque_value', 'offset': -12.8, 'order': 'intel', 'physical_range': '[-12.7|12.6]', 'physical_unit': 'Nm', 'precision': 0.1, 'type': 'double'}
double Epsfstatus401::epsf_steering_wheel_torque_value(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 0.100000 + -12.800000;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'epsf_work_mode_status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Epsfstatus401::epsf_work_mode_status(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace devkit
}  // namespace canbus
}  // namespace apollo
