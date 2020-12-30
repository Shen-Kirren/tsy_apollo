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

#include "modules/canbus/vehicle/devkit/protocol/iecu_control_steering_502.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace devkit {

using ::apollo::drivers::canbus::Byte;

const int32_t Iecucontrolsteering502::ID = 0x502;

// public
Iecucontrolsteering502::Iecucontrolsteering502() { Reset(); }

uint32_t Iecucontrolsteering502::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Iecucontrolsteering502::UpdateData(uint8_t* data) {
  set_p_iecu_rtire_angle_cmd(data, iecu_rtire_angle_cmd_);
  set_p_iecu_ftire_angle_cmd(data, iecu_ftire_angle_cmd_);
  set_p_iecu_rtire_speed_cmd(data, iecu_rtire_speed_cmd_);
  set_p_iecu_ftire_speed_cmd(data, iecu_ftire_speed_cmd_);
  set_p_iecu_steering_valid(data, iecu_steering_valid_);
}

void Iecucontrolsteering502::Reset() {
  // TODO(All) :  you should check this manually
  iecu_rtire_angle_cmd_ = 0.0;
  iecu_ftire_angle_cmd_ = 0.0;
  iecu_rtire_speed_cmd_ = 0;
  iecu_ftire_speed_cmd_ = 0;
  iecu_steering_valid_ = Iecu_control_steering_502::IECU_STEERING_VALID_STR_DISABLE;
}

Iecucontrolsteering502* Iecucontrolsteering502::set_iecu_rtire_angle_cmd(
    double iecu_rtire_angle_cmd) {
  iecu_rtire_angle_cmd_ = iecu_rtire_angle_cmd;
  return this;
 }

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'iECU_RTire_Angle_Cmd', 'offset': -30.0, 'order': 'intel', 'physical_range': '[-30|30]', 'physical_unit': 'deg', 'precision': 0.1, 'type': 'double'}
void Iecucontrolsteering502::set_p_iecu_rtire_angle_cmd(uint8_t* data,
    double iecu_rtire_angle_cmd) {
  iecu_rtire_angle_cmd = ProtocolData::BoundedValue(-30.0, 30.0, iecu_rtire_angle_cmd);
  int x = (iecu_rtire_angle_cmd - -30.000000) / 0.100000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 6);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 7);
  to_set1.set_value(t, 0, 8);
}


Iecucontrolsteering502* Iecucontrolsteering502::set_iecu_ftire_angle_cmd(
    double iecu_ftire_angle_cmd) {
  iecu_ftire_angle_cmd_ = iecu_ftire_angle_cmd;
  return this;
 }

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'iECU_FTire_Angle_Cmd', 'offset': -30.0, 'order': 'intel', 'physical_range': '[-30|30]', 'physical_unit': 'deg', 'precision': 0.1, 'type': 'double'}
void Iecucontrolsteering502::set_p_iecu_ftire_angle_cmd(uint8_t* data,
    double iecu_ftire_angle_cmd) {
  iecu_ftire_angle_cmd = ProtocolData::BoundedValue(-30.0, 30.0, iecu_ftire_angle_cmd);
  int x = (iecu_ftire_angle_cmd - -30.000000) / 0.100000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 4);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 5);
  to_set1.set_value(t, 0, 8);
}


Iecucontrolsteering502* Iecucontrolsteering502::set_iecu_rtire_speed_cmd(
    int iecu_rtire_speed_cmd) {
  iecu_rtire_speed_cmd_ = iecu_rtire_speed_cmd;
  return this;
 }

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'iECU_RTire_Speed_Cmd', 'offset': 20.0, 'order': 'intel', 'physical_range': '[20|250]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
void Iecucontrolsteering502::set_p_iecu_rtire_speed_cmd(uint8_t* data,
    int iecu_rtire_speed_cmd) {
  iecu_rtire_speed_cmd = ProtocolData::BoundedValue(20, 250, iecu_rtire_speed_cmd);
  int x = (iecu_rtire_speed_cmd - 20.000000);

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 8);
}


Iecucontrolsteering502* Iecucontrolsteering502::set_iecu_ftire_speed_cmd(
    int iecu_ftire_speed_cmd) {
  iecu_ftire_speed_cmd_ = iecu_ftire_speed_cmd;
  return this;
 }

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'iECU_FTire_Speed_Cmd', 'offset': 20.0, 'order': 'intel', 'physical_range': '[20|250]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
void Iecucontrolsteering502::set_p_iecu_ftire_speed_cmd(uint8_t* data,
    int iecu_ftire_speed_cmd) {
  iecu_ftire_speed_cmd = ProtocolData::BoundedValue(20, 250, iecu_ftire_speed_cmd);
  int x = (iecu_ftire_speed_cmd - 20.000000);

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 8);
}


Iecucontrolsteering502* Iecucontrolsteering502::set_iecu_steering_valid(
    Iecu_control_steering_502::Iecu_steering_validType iecu_steering_valid) {
  iecu_steering_valid_ = iecu_steering_valid;
  return this;
 }

// config detail: {'bit': 0, 'enum': {0: 'IECU_STEERING_VALID_STR_DISABLE', 1: 'IECU_STEERING_VALID_STR_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Steering_Valid', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
void Iecucontrolsteering502::set_p_iecu_steering_valid(uint8_t* data,
    Iecu_control_steering_502::Iecu_steering_validType iecu_steering_valid) {
  int x = iecu_steering_valid;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo
