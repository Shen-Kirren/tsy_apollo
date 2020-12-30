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

class Iecucontrolsteering502 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Iecucontrolsteering502();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'iECU_RTire_Angle_Cmd', 'offset': -30.0, 'order': 'intel', 'physical_range': '[-30|30]', 'physical_unit': 'deg', 'precision': 0.1, 'type': 'double'}
  Iecucontrolsteering502* set_iecu_rtire_angle_cmd(double iecu_rtire_angle_cmd);

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'iECU_FTire_Angle_Cmd', 'offset': -30.0, 'order': 'intel', 'physical_range': '[-30|30]', 'physical_unit': 'deg', 'precision': 0.1, 'type': 'double'}
  Iecucontrolsteering502* set_iecu_ftire_angle_cmd(double iecu_ftire_angle_cmd);

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'iECU_RTire_Speed_Cmd', 'offset': 20.0, 'order': 'intel', 'physical_range': '[20|250]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
  Iecucontrolsteering502* set_iecu_rtire_speed_cmd(int iecu_rtire_speed_cmd);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'iECU_FTire_Speed_Cmd', 'offset': 20.0, 'order': 'intel', 'physical_range': '[20|250]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
  Iecucontrolsteering502* set_iecu_ftire_speed_cmd(int iecu_ftire_speed_cmd);

  // config detail: {'bit': 0, 'enum': {0: 'IECU_STEERING_VALID_STR_DISABLE', 1: 'IECU_STEERING_VALID_STR_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Steering_Valid', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  Iecucontrolsteering502* set_iecu_steering_valid(Iecu_control_steering_502::Iecu_steering_validType iecu_steering_valid);

 private:

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'iECU_RTire_Angle_Cmd', 'offset': -30.0, 'order': 'intel', 'physical_range': '[-30|30]', 'physical_unit': 'deg', 'precision': 0.1, 'type': 'double'}
  void set_p_iecu_rtire_angle_cmd(uint8_t* data, double iecu_rtire_angle_cmd);

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'iECU_FTire_Angle_Cmd', 'offset': -30.0, 'order': 'intel', 'physical_range': '[-30|30]', 'physical_unit': 'deg', 'precision': 0.1, 'type': 'double'}
  void set_p_iecu_ftire_angle_cmd(uint8_t* data, double iecu_ftire_angle_cmd);

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'iECU_RTire_Speed_Cmd', 'offset': 20.0, 'order': 'intel', 'physical_range': '[20|250]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
  void set_p_iecu_rtire_speed_cmd(uint8_t* data, int iecu_rtire_speed_cmd);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'iECU_FTire_Speed_Cmd', 'offset': 20.0, 'order': 'intel', 'physical_range': '[20|250]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
  void set_p_iecu_ftire_speed_cmd(uint8_t* data, int iecu_ftire_speed_cmd);

  // config detail: {'bit': 0, 'enum': {0: 'IECU_STEERING_VALID_STR_DISABLE', 1: 'IECU_STEERING_VALID_STR_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name': 'iECU_Steering_Valid', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'enum'}
  void set_p_iecu_steering_valid(uint8_t* data, Iecu_control_steering_502::Iecu_steering_validType iecu_steering_valid);

 private:
  double iecu_rtire_angle_cmd_;
  double iecu_ftire_angle_cmd_;
  int iecu_rtire_speed_cmd_;
  int iecu_ftire_speed_cmd_;
  Iecu_control_steering_502::Iecu_steering_validType iecu_steering_valid_;
};

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo


