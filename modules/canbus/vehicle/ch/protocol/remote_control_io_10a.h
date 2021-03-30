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

class Remotecontrolio10a : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Remotecontrolio10a();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 56, 'is_signed_var': False, 'len': 8, 'name': 'D_ReverseSteeringMode_Flag', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int d_reversesteeringmode_flag(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 8, 'name': 'Remote_C_Reserved', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int remote_c_reserved(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 40, 'is_signed_var': False, 'len': 8, 'name': 'Remote_B_iECU_Request', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int remote_b_iecu_request(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'Remote_A_Torque_Request', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int remote_a_torque_request(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 24, 'is_signed_var': False, 'len': 8, 'name': 'Remote_F_EPB_Control', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int remote_f_epb_control(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'Remote_H_SteeringMode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int remote_h_steeringmode(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'Remote_G_SpeedLim', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int remote_g_speedlim(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'Remote_E_Gear', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int remote_e_gear(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace ch
}  // namespace canbus
}  // namespace apollo


