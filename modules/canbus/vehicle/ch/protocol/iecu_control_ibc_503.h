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
namespace ch {

class Iecucontrolibc503 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Iecucontrolibc503();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'iECU_BrakePressure_Cmd', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Iecucontrolibc503* set_iecu_brakepressure_cmd(int iecu_brakepressure_cmd);

  // config detail: {'bit': 0, 'enum': {0: 'IECU_IBC_VALID_BRK_DISABLE', 1: 'IECU_IBC_VALID_BRK_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_IBC_Valid', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  Iecucontrolibc503* set_iecu_ibc_valid(Iecu_control_ibc_503::Iecu_ibc_validType iecu_ibc_valid);

 private:

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'iECU_BrakePressure_Cmd', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_iecu_brakepressure_cmd(uint8_t* data, int iecu_brakepressure_cmd);

  // config detail: {'bit': 0, 'enum': {0: 'IECU_IBC_VALID_BRK_DISABLE', 1: 'IECU_IBC_VALID_BRK_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_IBC_Valid', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  void set_p_iecu_ibc_valid(uint8_t* data, Iecu_control_ibc_503::Iecu_ibc_validType iecu_ibc_valid);

 private:
  int iecu_brakepressure_cmd_;
  Iecu_control_ibc_503::Iecu_ibc_validType iecu_ibc_valid_;
};

}  // namespace ch
}  // namespace canbus
}  // namespace apollo


