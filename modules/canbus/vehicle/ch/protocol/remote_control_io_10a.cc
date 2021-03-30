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

#include "modules/canbus/vehicle/ch/protocol/remote_control_io_10a.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

Remotecontrolio10a::Remotecontrolio10a() {}
const int32_t Remotecontrolio10a::ID = 0x10A;

void Remotecontrolio10a::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_ch()->mutable_remote_control_io_10a()->set_d_reversesteeringmode_flag(d_reversesteeringmode_flag(bytes, length));
  chassis->mutable_ch()->mutable_remote_control_io_10a()->set_remote_c_reserved(remote_c_reserved(bytes, length));
  chassis->mutable_ch()->mutable_remote_control_io_10a()->set_remote_b_iecu_request(remote_b_iecu_request(bytes, length));
  chassis->mutable_ch()->mutable_remote_control_io_10a()->set_remote_a_torque_request(remote_a_torque_request(bytes, length));
  chassis->mutable_ch()->mutable_remote_control_io_10a()->set_remote_f_epb_control(remote_f_epb_control(bytes, length));
  chassis->mutable_ch()->mutable_remote_control_io_10a()->set_remote_h_steeringmode(remote_h_steeringmode(bytes, length));
  chassis->mutable_ch()->mutable_remote_control_io_10a()->set_remote_g_speedlim(remote_g_speedlim(bytes, length));
  chassis->mutable_ch()->mutable_remote_control_io_10a()->set_remote_e_gear(remote_e_gear(bytes, length));

  chassis->mutable_check_response()->set_is_eps_online(remote_c_reserved(bytes, length) == 0);
  chassis->mutable_check_response()->set_is_esp_online(remote_c_reserved(bytes, length) == 0);
  chassis->mutable_check_response()->set_is_vcu_online(remote_c_reserved(bytes, length) == 0);
}

// config detail: {'bit': 56, 'is_signed_var': False, 'len': 8, 'name': 'd_reversesteeringmode_flag', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Remotecontrolio10a::d_reversesteeringmode_flag(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 8, 'name': 'remote_c_reserved', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Remotecontrolio10a::remote_c_reserved(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 40, 'is_signed_var': False, 'len': 8, 'name': 'remote_b_iecu_request', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Remotecontrolio10a::remote_b_iecu_request(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'remote_a_torque_request', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Remotecontrolio10a::remote_a_torque_request(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 24, 'is_signed_var': False, 'len': 8, 'name': 'remote_f_epb_control', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Remotecontrolio10a::remote_f_epb_control(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'remote_h_steeringmode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Remotecontrolio10a::remote_h_steeringmode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'remote_g_speedlim', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Remotecontrolio10a::remote_g_speedlim(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'remote_e_gear', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Remotecontrolio10a::remote_e_gear(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace ch
}  // namespace canbus
}  // namespace apollo
