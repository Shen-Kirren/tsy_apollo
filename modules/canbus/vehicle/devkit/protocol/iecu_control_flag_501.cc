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

#include "modules/canbus/vehicle/devkit/protocol/iecu_control_flag_501.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace devkit {

using ::apollo::drivers::canbus::Byte;

const int32_t Iecucontrolflag501::ID = 0x501;

// public
Iecucontrolflag501::Iecucontrolflag501() { Reset(); }

uint32_t Iecucontrolflag501::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Iecucontrolflag501::UpdateData(uint8_t* data) {
  set_p_iecu_control_request_flag(data, iecu_control_request_flag_);
}

void Iecucontrolflag501::Reset() {
  // TODO(All) :  you should check this manually
  iecu_control_request_flag_ = Iecu_control_flag_501::IECU_CONTROL_REQUEST_FLAG_IECU_DISABLE;
}

Iecucontrolflag501* Iecucontrolflag501::set_iecu_control_request_flag(
    Iecu_control_flag_501::Iecu_control_request_flagType iecu_control_request_flag) {
  iecu_control_request_flag_ = iecu_control_request_flag;
  return this;
 }

// config detail: {'bit': 0, 'enum': {0: 'IECU_CONTROL_REQUEST_FLAG_IECU_DISABLE', 1: 'IECU_CONTROL_REQUEST_FLAG_IECU_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Control_Request_Flag', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
void Iecucontrolflag501::set_p_iecu_control_request_flag(uint8_t* data,
    Iecu_control_flag_501::Iecu_control_request_flagType iecu_control_request_flag) {
  int x = iecu_control_request_flag;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo
