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

#include "modules/canbus/vehicle/ch/protocol/vcu_vehicle_status_1_303.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

Vcuvehiclestatus1303::Vcuvehiclestatus1303() {}
const int32_t Vcuvehiclestatus1303::ID = 0x303;

void Vcuvehiclestatus1303::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_ch()->mutable_vcu_vehicle_status_1_303()->set_vehicle_status_reserved(vehicle_status_reserved(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_status_1_303()->set_bms_status(bms_status(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_status_1_303()->set_ignitionstatus(ignitionstatus(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_status_1_303()->set_gear_rpt(gear_rpt(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_status_1_303()->set_epb_rpt(epb_rpt(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_status_1_303()->set_vcu_ready_flag(vcu_ready_flag(bytes, length));
}

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'vehicle_status_reserved', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Vcuvehiclestatus1303::vehicle_status_reserved(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'bms_status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Vcuvehiclestatus1303::bms_status(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'ignitionstatus', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Vcuvehiclestatus1303::ignitionstatus(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 8, 'enum': {0: 'GEAR_RPT_INVALID', 1: 'GEAR_RPT_DRIVE', 2: 'GEAR_RPT_NEUTRAL', 3: 'GEAR_RPT_REVERSE', 4: 'GEAR_RPT_PARKING'}, 'is_signed_var': False, 'len': 8, 'name': 'gear_rpt', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_status_1_303::Gear_rptType Vcuvehiclestatus1303::gear_rpt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Vcu_vehicle_status_1_303::Gear_rptType ret =  static_cast<Vcu_vehicle_status_1_303::Gear_rptType>(x);
  return ret;
}

// config detail: {'bit': 24, 'enum': {0: 'EPB_RPT_EPB_NONE', 1: 'EPB_RPT_EPB_ON', 2: 'EPB_RPT_EPB_OFF'}, 'is_signed_var': False, 'len': 8, 'name': 'epb_rpt', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_status_1_303::Epb_rptType Vcuvehiclestatus1303::epb_rpt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Vcu_vehicle_status_1_303::Epb_rptType ret =  static_cast<Vcu_vehicle_status_1_303::Epb_rptType>(x);
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'vcu_ready_flag', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Vcuvehiclestatus1303::vcu_ready_flag(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace ch
}  // namespace canbus
}  // namespace apollo
