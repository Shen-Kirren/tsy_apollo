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

#include "modules/canbus/vehicle/ch/protocol/vcu_vehicle_status_3_305.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

Vcuvehiclestatus3305::Vcuvehiclestatus3305() {}
const int32_t Vcuvehiclestatus3305::ID = 0x305;

void Vcuvehiclestatus3305::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_ch()->mutable_vcu_vehicle_status_3_305()->set_rpm_rr_rpt(rpm_rr_rpt(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_status_3_305()->set_rpm_rl_rpt(rpm_rl_rpt(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_status_3_305()->set_rpm_fr_rpt(rpm_fr_rpt(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_status_3_305()->set_rpm_fl_rpt(rpm_fl_rpt(bytes, length));
}

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'rpm_rr_rpt', 'offset': -10000.0, 'order': 'intel', 'physical_range': '[-10000|-3446.5]', 'physical_unit': 'rpm', 'precision': 0.1, 'type': 'double'}
double Vcuvehiclestatus3305::rpm_rr_rpt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000 + -10000.000000;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'rpm_rl_rpt', 'offset': -10000.0, 'order': 'intel', 'physical_range': '[-10000|-3446.5]', 'physical_unit': 'rpm', 'precision': 0.1, 'type': 'double'}
double Vcuvehiclestatus3305::rpm_rl_rpt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000 + -10000.000000;
  return ret;
}

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'rpm_fr_rpt', 'offset': -10000.0, 'order': 'intel', 'physical_range': '[-10000|-3446.5]', 'physical_unit': 'rpm', 'precision': 0.1, 'type': 'double'}
double Vcuvehiclestatus3305::rpm_fr_rpt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000 + -10000.000000;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'rpm_fl_rpt', 'offset': -10000.0, 'order': 'intel', 'physical_range': '[-10000|-3446.5]', 'physical_unit': 'rpm', 'precision': 0.1, 'type': 'double'}
double Vcuvehiclestatus3305::rpm_fl_rpt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000 + -10000.000000;
  return ret;
}
}  // namespace ch
}  // namespace canbus
}  // namespace apollo
