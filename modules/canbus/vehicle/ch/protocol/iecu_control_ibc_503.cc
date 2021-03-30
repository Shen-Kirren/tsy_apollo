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

#include "modules/canbus/vehicle/ch/protocol/iecu_control_ibc_503.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

const int32_t Iecucontrolibc503::ID = 0x503;

// public
Iecucontrolibc503::Iecucontrolibc503() { Reset(); }

uint32_t Iecucontrolibc503::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Iecucontrolibc503::UpdateData(uint8_t* data) {
  set_p_iecu_brakepressure_cmd(data, iecu_brakepressure_cmd_);
  set_p_iecu_ibc_valid(data, iecu_ibc_valid_);
}

void Iecucontrolibc503::Reset() {
  // TODO(All) :  you should check this manually
  iecu_brakepressure_cmd_ = 0;
  iecu_ibc_valid_ = Iecu_control_ibc_503::IECU_IBC_VALID_BRK_DISABLE;
}

Iecucontrolibc503* Iecucontrolibc503::set_iecu_brakepressure_cmd(
    int iecu_brakepressure_cmd) {
  iecu_brakepressure_cmd_ = iecu_brakepressure_cmd;
  return this;
 }

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'iECU_BrakePressure_Cmd', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Iecucontrolibc503::set_p_iecu_brakepressure_cmd(uint8_t* data,
    int iecu_brakepressure_cmd) {
  iecu_brakepressure_cmd = ProtocolData::BoundedValue(0, 100, iecu_brakepressure_cmd);
  int x = iecu_brakepressure_cmd;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 8);
}


Iecucontrolibc503* Iecucontrolibc503::set_iecu_ibc_valid(
    Iecu_control_ibc_503::Iecu_ibc_validType iecu_ibc_valid) {
  iecu_ibc_valid_ = iecu_ibc_valid;
  return this;
 }

// config detail: {'bit': 0, 'enum': {0: 'IECU_IBC_VALID_BRK_DISABLE', 1: 'IECU_IBC_VALID_BRK_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_IBC_Valid', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
void Iecucontrolibc503::set_p_iecu_ibc_valid(uint8_t* data,
    Iecu_control_ibc_503::Iecu_ibc_validType iecu_ibc_valid) {
  int x = iecu_ibc_valid;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
