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

class Iecucontrolflag501 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Iecucontrolflag501();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 0, 'enum': {0: 'IECU_CONTROL_REQUEST_FLAG_IECU_DISABLE', 1: 'IECU_CONTROL_REQUEST_FLAG_IECU_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Control_Request_Flag', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  Iecucontrolflag501* set_iecu_control_request_flag(Iecu_control_flag_501::Iecu_control_request_flagType iecu_control_request_flag);

 private:

  // config detail: {'bit': 0, 'enum': {0: 'IECU_CONTROL_REQUEST_FLAG_IECU_DISABLE', 1: 'IECU_CONTROL_REQUEST_FLAG_IECU_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Control_Request_Flag', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  void set_p_iecu_control_request_flag(uint8_t* data, Iecu_control_flag_501::Iecu_control_request_flagType iecu_control_request_flag);

 private:
  Iecu_control_flag_501::Iecu_control_request_flagType iecu_control_request_flag_;
};

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo


