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

#include "modules/canbus/vehicle/ch/protocol/iecu_control_power_504.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

const int32_t Iecucontrolpower504::ID = 0x504;

// public
Iecucontrolpower504::Iecucontrolpower504() { Reset(); }

uint32_t Iecucontrolpower504::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Iecucontrolpower504::UpdateData(uint8_t* data) {
  set_p_iecu_power_speed(data, iecu_power_speed_);
  set_p_iecu_power_torque(data, iecu_power_torque_);
  set_p_iecu_acc_de_control(data, iecu_acc_de_control_);
  set_p_iecu_power_gear(data, iecu_power_gear_);
  set_p_iecu_torque_or_speed_or_acc(data, iecu_torque_or_speed_or_acc_);
  set_p_iecu_total_or_distribute(data, iecu_total_or_distribute_);
  set_p_iecu_power_valid(data, iecu_power_valid_);
}

void Iecucontrolpower504::Reset() {
  // TODO(All) :  you should check this manually
  iecu_power_speed_ = 0.0;
  iecu_power_torque_ = 0;
  iecu_acc_de_control_ = 0;
  iecu_power_gear_ = Iecu_control_power_504::IECU_POWER_GEAR_PARK_CMD;
  iecu_torque_or_speed_or_acc_ = Iecu_control_power_504::IECU_TORQUE_OR_SPEED_OR_ACC_POW_TORQUE;
  iecu_total_or_distribute_ = Iecu_control_power_504::IECU_TOTAL_OR_DISTRIBUTE_POW_TOTAL;
  iecu_power_valid_ = Iecu_control_power_504::IECU_POWER_VALID_POW_DISABLE;
}

Iecucontrolpower504* Iecucontrolpower504::set_iecu_power_speed(
    double iecu_power_speed) {
  iecu_power_speed_ = iecu_power_speed;
  return this;
 }

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_Speed', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|80]', 'physical_unit': 'km/h', 'precision': 0.1, 'type': 'double'}
void Iecucontrolpower504::set_p_iecu_power_speed(uint8_t* data,
    double iecu_power_speed) {
  iecu_power_speed = ProtocolData::BoundedValue(0.0, 80.0, iecu_power_speed);
  int x = iecu_power_speed / 0.100000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 6);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 7);
  to_set1.set_value(t, 0, 8);
}


Iecucontrolpower504* Iecucontrolpower504::set_iecu_power_torque(
    int iecu_power_torque) {
  iecu_power_torque_ = iecu_power_torque;
  return this;
 }

// config detail: {'bit': 40, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Power_Torque', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
void Iecucontrolpower504::set_p_iecu_power_torque(uint8_t* data,
    int iecu_power_torque) {
  iecu_power_torque = ProtocolData::BoundedValue(0, 100, iecu_power_torque);
  int x = iecu_power_torque;

  Byte to_set(data + 5);
  to_set.set_value(x, 0, 8);
}


Iecucontrolpower504* Iecucontrolpower504::set_iecu_acc_de_control(
    int iecu_acc_de_control) {
  iecu_acc_de_control_ = iecu_acc_de_control;
  return this;
 }

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Acc_De_Control', 'offset': -100.0, 'order': 'intel', 'physical_range': '[-100|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
void Iecucontrolpower504::set_p_iecu_acc_de_control(uint8_t* data,
    int iecu_acc_de_control) {
  iecu_acc_de_control = ProtocolData::BoundedValue(-100, 100, iecu_acc_de_control);
  int x = (iecu_acc_de_control - -100.000000);

  Byte to_set(data + 4);
  to_set.set_value(x, 0, 8);
}


Iecucontrolpower504* Iecucontrolpower504::set_iecu_power_gear(
    Iecu_control_power_504::Iecu_power_gearType iecu_power_gear) {
  iecu_power_gear_ = iecu_power_gear;
  return this;
 }

// config detail: {'bit': 24, 'enum': {0: 'IECU_POWER_GEAR_PARK_CMD', 1: 'IECU_POWER_GEAR_DRIVE_CMD', 2: 'IECU_POWER_GEAR_NEUTRAL_CMD', 3: 'IECU_POWER_GEAR_REVERSE_CMD'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Power_Gear', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
void Iecucontrolpower504::set_p_iecu_power_gear(uint8_t* data,
    Iecu_control_power_504::Iecu_power_gearType iecu_power_gear) {
  int x = iecu_power_gear;

  Byte to_set(data + 3);
  to_set.set_value(x, 0, 8);
}


Iecucontrolpower504* Iecucontrolpower504::set_iecu_torque_or_speed_or_acc(
    Iecu_control_power_504::Iecu_torque_or_speed_or_accType iecu_torque_or_speed_or_acc) {
  iecu_torque_or_speed_or_acc_ = iecu_torque_or_speed_or_acc;
  return this;
 }

// config detail: {'bit': 16, 'enum': {0: 'IECU_TORQUE_OR_SPEED_OR_ACC_POW_TORQUE', 1: 'IECU_TORQUE_OR_SPEED_OR_ACC_POW_SPEED', 2: 'IECU_TORQUE_OR_SPEED_OR_ACC_POW_ACC'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_torque_or_speed_or_Acc', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
void Iecucontrolpower504::set_p_iecu_torque_or_speed_or_acc(uint8_t* data,
    Iecu_control_power_504::Iecu_torque_or_speed_or_accType iecu_torque_or_speed_or_acc) {
  int x = iecu_torque_or_speed_or_acc;

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 8);
}


Iecucontrolpower504* Iecucontrolpower504::set_iecu_total_or_distribute(
    Iecu_control_power_504::Iecu_total_or_distributeType iecu_total_or_distribute) {
  iecu_total_or_distribute_ = iecu_total_or_distribute;
  return this;
 }

// config detail: {'bit': 8, 'enum': {0: 'IECU_TOTAL_OR_DISTRIBUTE_POW_TOTAL', 1: 'IECU_TOTAL_OR_DISTRIBUTE_POW_DISTRIBUTED'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_total_or_distribute', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
void Iecucontrolpower504::set_p_iecu_total_or_distribute(uint8_t* data,
    Iecu_control_power_504::Iecu_total_or_distributeType iecu_total_or_distribute) {
  int x = iecu_total_or_distribute;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 8);
}


Iecucontrolpower504* Iecucontrolpower504::set_iecu_power_valid(
    Iecu_control_power_504::Iecu_power_validType iecu_power_valid) {
  iecu_power_valid_ = iecu_power_valid;
  return this;
 }

// config detail: {'bit': 0, 'enum': {0: 'IECU_POWER_VALID_POW_DISABLE', 1: 'IECU_POWER_VALID_POW_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Power_Valid', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
void Iecucontrolpower504::set_p_iecu_power_valid(uint8_t* data,
    Iecu_control_power_504::Iecu_power_validType iecu_power_valid) {
  int x = iecu_power_valid;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
