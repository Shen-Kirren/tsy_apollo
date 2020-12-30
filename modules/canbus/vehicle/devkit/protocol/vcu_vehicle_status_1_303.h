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

class Vcuvehiclestatus1303 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Vcuvehiclestatus1303();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'Vehicle_Status_Reserved', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int vehicle_status_reserved(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'BMS_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int bms_status(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'IgnitionStatus', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int ignitionstatus(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'enum': {0: 'GEAR_RPT_INVALID', 1: 'GEAR_RPT_DRIVE', 2: 'GEAR_RPT_NEUTRAL', 3: 'GEAR_RPT_REVERSE', 4: 'GEAR_RPT_PARKING'}, 'is_signed_var': False, 'len': 8, 'name': 'gear_rpt', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_status_1_303::Gear_rptType gear_rpt(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 24, 'enum': {0: 'EPB_RPT_EPB_NONE', 1: 'EPB_RPT_EPB_ON', 2: 'EPB_RPT_EPB_OFF'}, 'is_signed_var': False, 'len': 8, 'name': 'epb_rpt', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_status_1_303::Epb_rptType epb_rpt(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'VCU_Ready_Flag', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
  int vcu_ready_flag(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo


