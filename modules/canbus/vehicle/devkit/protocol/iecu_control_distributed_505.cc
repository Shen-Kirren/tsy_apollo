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

#include "modules/canbus/vehicle/devkit/protocol/iecu_control_distributed_505.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace devkit {

using ::apollo::drivers::canbus::Byte;

const int32_t Iecucontroldistributed505::ID = 0x505;

// public
Iecucontroldistributed505::Iecucontroldistributed505() { Reset(); }

uint32_t Iecucontroldistributed505::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Iecucontroldistributed505::UpdateData(uint8_t* data) {
  set_p_iecu_power_rr(data, iecu_power_rr_);
  set_p_iecu_power_rl(data, iecu_power_rl_);
  set_p_iecu_power_fr(data, iecu_power_fr_);
  set_p_iecu_power_fl(data, iecu_power_fl_);
}

void Iecucontroldistributed505::Reset() {
  // TODO(All) :  you should check this manually
  iecu_power_rr_ = 0;
  iecu_power_rl_ = 0;
  iecu_power_fr_ = 0;
  iecu_power_fl_ = 0;
}

Iecucontroldistributed505* Iecucontroldistributed505::set_iecu_power_rr(
    int iecu_power_rr) {
  iecu_power_rr_ = iecu_power_rr;
  return this;
 }

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_RR', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
void Iecucontroldistributed505::set_p_iecu_power_rr(uint8_t* data,
    int iecu_power_rr) {
  iecu_power_rr = ProtocolData::BoundedValue(0, 800, iecu_power_rr);
  int x = iecu_power_rr;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 6);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 7);
  to_set1.set_value(t, 0, 8);
}


Iecucontroldistributed505* Iecucontroldistributed505::set_iecu_power_rl(
    int iecu_power_rl) {
  iecu_power_rl_ = iecu_power_rl;
  return this;
 }

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_RL', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
void Iecucontroldistributed505::set_p_iecu_power_rl(uint8_t* data,
    int iecu_power_rl) {
  iecu_power_rl = ProtocolData::BoundedValue(0, 800, iecu_power_rl);
  int x = iecu_power_rl;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 4);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 5);
  to_set1.set_value(t, 0, 8);
}


Iecucontroldistributed505* Iecucontroldistributed505::set_iecu_power_fr(
    int iecu_power_fr) {
  iecu_power_fr_ = iecu_power_fr;
  return this;
 }

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_FR', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
void Iecucontroldistributed505::set_p_iecu_power_fr(uint8_t* data,
    int iecu_power_fr) {
  iecu_power_fr = ProtocolData::BoundedValue(0, 800, iecu_power_fr);
  int x = iecu_power_fr;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 2);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 3);
  to_set1.set_value(t, 0, 8);
}


Iecucontroldistributed505* Iecucontroldistributed505::set_iecu_power_fl(
    int iecu_power_fl) {
  iecu_power_fl_ = iecu_power_fl;
  return this;
 }

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_FL', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
void Iecucontroldistributed505::set_p_iecu_power_fl(uint8_t* data,
    int iecu_power_fl) {
  iecu_power_fl = ProtocolData::BoundedValue(0, 800, iecu_power_fl);
  int x = iecu_power_fl;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 0);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 1);
  to_set1.set_value(t, 0, 8);
}

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo
