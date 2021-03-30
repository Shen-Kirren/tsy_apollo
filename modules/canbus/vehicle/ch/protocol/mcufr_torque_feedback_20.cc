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

#include "modules/canbus/vehicle/ch/protocol/mcufr_torque_feedback_20.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

Mcufrtorquefeedback20::Mcufrtorquefeedback20() {}
const int32_t Mcufrtorquefeedback20::ID = 0x20;

void Mcufrtorquefeedback20::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_ch()->mutable_mcufr_torque_feedback_20()->set_fr_torque(fr_torque(bytes, length));
  chassis->mutable_ch()->mutable_mcufr_torque_feedback_20()->set_fr_speed(fr_speed(bytes, length));
  chassis->mutable_ch()->mutable_mcufr_torque_feedback_20()->set_fr_shift(fr_shift(bytes, length));
  chassis->mutable_ch()->mutable_mcufr_torque_feedback_20()->set_fr_motortemp(fr_motortemp(bytes, length));
  chassis->mutable_ch()->mutable_mcufr_torque_feedback_20()->set_fr_errorcode(fr_errorcode(bytes, length));
  chassis->mutable_ch()->mutable_mcufr_torque_feedback_20()->set_fr_current(fr_current(bytes, length));
}

// config detail: {'bit': 20, 'is_signed_var': False, 'len': 16, 'name': 'fr_torque', 'offset': -1000.0, 'order': 'intel', 'physical_range': '[-1000|1000]', 'physical_unit': 'Nm', 'precision': 0.1, 'type': 'double'}
double Mcufrtorquefeedback20::fr_torque(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 4);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 2);
  t = t2.get_byte(4, 4);
  x <<= 4;
  x |= t;

  double ret = x * 0.100000 + -1000.000000;
  return ret;
}

// config detail: {'bit': 2, 'is_signed_var': False, 'len': 18, 'name': 'fr_speed', 'offset': -10000.0, 'order': 'intel', 'physical_range': '[-10000|10000]', 'physical_unit': 'rpm', 'precision': 0.1, 'type': 'double'}
double Mcufrtorquefeedback20::fr_speed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 4);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 0);
  t = t2.get_byte(2, 6);
  x <<= 6;
  x |= t;

  double ret = x * 0.100000 + -10000.000000;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'fr_shift', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Mcufrtorquefeedback20::fr_shift(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 8, 'name': 'fr_motortemp', 'offset': -50.0, 'order': 'intel', 'physical_range': '[-50|205]', 'physical_unit': 'DU', 'precision': 1.0, 'type': 'int'}
int Mcufrtorquefeedback20::fr_motortemp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  int ret = x + -50.000000;
  return ret;
}

// config detail: {'bit': 56, 'is_signed_var': False, 'len': 8, 'name': 'fr_errorcode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Mcufrtorquefeedback20::fr_errorcode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 36, 'is_signed_var': False, 'len': 12, 'name': 'fr_current', 'offset': -500.0, 'order': 'intel', 'physical_range': '[-500|500]', 'physical_unit': 'A', 'precision': 1.0, 'type': 'int'}
int Mcufrtorquefeedback20::fr_current(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(4, 4);
  x <<= 4;
  x |= t;

  int ret = x + -500.000000;
  return ret;
}
}  // namespace ch
}  // namespace canbus
}  // namespace apollo
