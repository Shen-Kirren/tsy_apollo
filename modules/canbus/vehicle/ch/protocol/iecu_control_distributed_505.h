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

class Iecucontroldistributed505 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Iecucontroldistributed505();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_RR', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
  Iecucontroldistributed505* set_iecu_power_rr(int iecu_power_rr);

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_RL', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
  Iecucontroldistributed505* set_iecu_power_rl(int iecu_power_rl);

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_FR', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
  Iecucontroldistributed505* set_iecu_power_fr(int iecu_power_fr);

  // config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_FL', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
  Iecucontroldistributed505* set_iecu_power_fl(int iecu_power_fl);

 private:

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_RR', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
  void set_p_iecu_power_rr(uint8_t* data, int iecu_power_rr);

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_RL', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
  void set_p_iecu_power_rl(uint8_t* data, int iecu_power_rl);

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_FR', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
  void set_p_iecu_power_fr(uint8_t* data, int iecu_power_fr);

  // config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'iECU_Power_FL', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|800]', 'physical_unit': 'Rpm/Nm', 'precision': 1.0, 'type': 'int'}
  void set_p_iecu_power_fl(uint8_t* data, int iecu_power_fl);

 private:
  int iecu_power_rr_;
  int iecu_power_rl_;
  int iecu_power_fr_;
  int iecu_power_fl_;
};

}  // namespace ch
}  // namespace canbus
}  // namespace apollo


