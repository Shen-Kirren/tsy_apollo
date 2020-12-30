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

#include "modules/canbus/vehicle/devkit/protocol/dbsf_status_142.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace devkit {

using ::apollo::drivers::canbus::Byte;

Dbsfstatus142::Dbsfstatus142() {}
const int32_t Dbsfstatus142::ID = 0x142;

void Dbsfstatus142::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_devkit()->mutable_dbsf_status_142()->set_dbsf_reserved_2(dbsf_reserved_2(bytes, length));
  chassis->mutable_devkit()->mutable_dbsf_status_142()->set_dbsf_fault_code(dbsf_fault_code(bytes, length));
  chassis->mutable_devkit()->mutable_dbsf_status_142()->set_dbsf_hp_pressure(dbsf_hp_pressure(bytes, length));
  chassis->mutable_devkit()->mutable_dbsf_status_142()->set_dbsf_reserved_1(dbsf_reserved_1(bytes, length));
  chassis->mutable_devkit()->mutable_dbsf_status_142()->set_dbsf_system_status(dbsf_system_status(bytes, length));
  //tsy_controller.cc中CheckReponse中要求的代码
  chassis->mutable_check_response()->set_is_esp_online(
      dbsf_fault_code(bytes, length) == 0);
}

// config detail: {'bit': 40, 'is_signed_var': False, 'len': 24, 'name': 'dbsf_reserved_2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Dbsfstatus142::dbsf_reserved_2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 5);
  t = t2.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'dbsf_fault_code', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Dbsfstatus142::dbsf_fault_code(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'dbsf_hp_pressure', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|8]', 'physical_unit': 'Mpa', 'precision': 0.01, 'type': 'double'}
double Dbsfstatus142::dbsf_hp_pressure(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'bit': 2, 'is_signed_var': False, 'len': 14, 'name': 'dbsf_reserved_1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Dbsfstatus142::dbsf_reserved_1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(2, 6);
  x <<= 6;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'dbsf_system_status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': 'N/A', 'precision': 1.0, 'type': 'int'}
int Dbsfstatus142::dbsf_system_status(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}
}  // namespace devkit
}  // namespace canbus
}  // namespace apollo
