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

#include "modules/canbus/vehicle/ch/protocol/vcu_vehicle_diagnosis_301.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

Vcuvehiclediagnosis301::Vcuvehiclediagnosis301() {}
const int32_t Vcuvehiclediagnosis301::ID = 0x301;

void Vcuvehiclediagnosis301::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_vehicle_diagnosis_reserved_3(vehicle_diagnosis_reserved_3(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_vehicle_diagnosis_reserved_1(vehicle_diagnosis_reserved_1(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_vehicle_diagnosis_reserved_2(vehicle_diagnosis_reserved_2(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_epb_state(epb_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_vehicle_fault_grade(vehicle_fault_grade(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_r_attach_switch_state(r_attach_switch_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_f_attach_switch_state(f_attach_switch_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_bms_state(bms_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_iecu_state(iecu_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_dbsr_state(dbsr_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_rlmotor_state(rlmotor_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_rrmotor_state(rrmotor_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_flmotor_state(flmotor_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_frmotor_state(frmotor_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_rsteering_state(rsteering_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_fsteering_state(fsteering_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_dbsf_state(dbsf_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_remote_state(remote_state(bytes, length));
  chassis->mutable_ch()->mutable_vcu_vehicle_diagnosis_301()->set_emergency_button_state(emergency_button_state(bytes, length));

  /*chassis->mutable_check_response()->set_is_eps_online(vehicle_fault_grade(bytes, length) == 0);
  chassis->mutable_check_response()->set_is_esp_online(vehicle_fault_grade(bytes, length) == 0);
  chassis->mutable_check_response()->set_is_vcu_online(vehicle_fault_grade(bytes, length) == 0);
  */
}

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'vehicle_diagnosis_reserved_3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcuvehiclediagnosis301::vehicle_diagnosis_reserved_3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 18, 'is_signed_var': False, 'len': 14, 'name': 'vehicle_diagnosis_reserved_1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcuvehiclediagnosis301::vehicle_diagnosis_reserved_1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(2, 6);
  x <<= 6;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'vehicle_diagnosis_reserved_2', 'offset': -0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcuvehiclediagnosis301::vehicle_diagnosis_reserved_2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 14, 'enum': {0: 'EPB_STATE_EPB_OK', 1: 'EPB_STATE_EPB_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'epb_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Epb_stateType Vcuvehiclediagnosis301::epb_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(6, 1);

  Vcu_vehicle_diagnosis_301::Epb_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Epb_stateType>(x);
  return ret;
}

// config detail: {'bit': 15, 'enum': {0: 'VEHICLE_FAULT_GRADE_CAR_OK', 1: 'VEHICLE_FAULT_GRADE_CAR_ERR1', 2: 'VEHICLE_FAULT_GRADE_CAR_ERR2', 3: 'VEHICLE_FAULT_GRADE_CAR_ERR3'}, 'is_signed_var': False, 'len': 2, 'name': 'vehicle_fault_grade', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Vehicle_fault_gradeType Vcuvehiclediagnosis301::vehicle_fault_grade(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 1);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(7, 1);
  x <<= 1;
  x |= t;

  Vcu_vehicle_diagnosis_301::Vehicle_fault_gradeType ret =  static_cast<Vcu_vehicle_diagnosis_301::Vehicle_fault_gradeType>(x);
  return ret;
}

// config detail: {'bit': 13, 'enum': {0: 'R_ATTACH_SWITCH_STATE_RATCH_OK', 1: 'R_ATTACH_SWITCH_STATE_RATCH_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'r_attach_switch_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::R_attach_switch_stateType Vcuvehiclediagnosis301::r_attach_switch_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(5, 1);

  Vcu_vehicle_diagnosis_301::R_attach_switch_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::R_attach_switch_stateType>(x);
  return ret;
}

// config detail: {'bit': 12, 'enum': {0: 'F_ATTACH_SWITCH_STATE_FATCH_OK', 1: 'F_ATTACH_SWITCH_STATE_FATCH_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'f_attach_switch_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::F_attach_switch_stateType Vcuvehiclediagnosis301::f_attach_switch_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 1);

  Vcu_vehicle_diagnosis_301::F_attach_switch_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::F_attach_switch_stateType>(x);
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'BMS_STATE_BMS_OK', 1: 'BMS_STATE_BMS_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'bms_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Bms_stateType Vcuvehiclediagnosis301::bms_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  Vcu_vehicle_diagnosis_301::Bms_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Bms_stateType>(x);
  return ret;
}

// config detail: {'bit': 6, 'enum': {0: 'IECU_STATE_IECU_OK', 1: 'IECU_STATE_IECU_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'iecu_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Iecu_stateType Vcuvehiclediagnosis301::iecu_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 1);

  Vcu_vehicle_diagnosis_301::Iecu_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Iecu_stateType>(x);
  return ret;
}

// config detail: {'bit': 8, 'enum': {0: 'DBSR_STATE_DBSR_OK', 1: 'DBSR_STATE_DBSR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'dbsr_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Dbsr_stateType Vcuvehiclediagnosis301::dbsr_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  Vcu_vehicle_diagnosis_301::Dbsr_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Dbsr_stateType>(x);
  return ret;
}

// config detail: {'bit': 4, 'enum': {0: 'RLMOTOR_STATE_RL_OK', 1: 'RLMOTOR_STATE_RL_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'rlmotor_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Rlmotor_stateType Vcuvehiclediagnosis301::rlmotor_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  Vcu_vehicle_diagnosis_301::Rlmotor_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Rlmotor_stateType>(x);
  return ret;
}

// config detail: {'bit': 3, 'enum': {0: 'RRMOTOR_STATE_RR_OK', 1: 'RRMOTOR_STATE_RR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'rrmotor_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Rrmotor_stateType Vcuvehiclediagnosis301::rrmotor_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(3, 1);

  Vcu_vehicle_diagnosis_301::Rrmotor_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Rrmotor_stateType>(x);
  return ret;
}

// config detail: {'bit': 2, 'enum': {0: 'FLMOTOR_STATE_FL_OK', 1: 'FLMOTOR_STATE_FL_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'flmotor_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Flmotor_stateType Vcuvehiclediagnosis301::flmotor_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 1);

  Vcu_vehicle_diagnosis_301::Flmotor_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Flmotor_stateType>(x);
  return ret;
}

// config detail: {'bit': 1, 'enum': {0: 'FRMOTOR_STATE_FR_OK', 1: 'FRMOTOR_STATE_FR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'frmotor_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Frmotor_stateType Vcuvehiclediagnosis301::frmotor_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(1, 1);

  Vcu_vehicle_diagnosis_301::Frmotor_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Frmotor_stateType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'RSTEERING_STATE_RSTR_OK', 1: 'RSTEERING_STATE_RSTR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'rsteering_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Rsteering_stateType Vcuvehiclediagnosis301::rsteering_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  Vcu_vehicle_diagnosis_301::Rsteering_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Rsteering_stateType>(x);
  return ret;
}

// config detail: {'bit': 10, 'enum': {0: 'FSTEERING_STATE_FSTR_OK', 1: 'FSTEERING_STATE_FSTR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'fsteering_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Fsteering_stateType Vcuvehiclediagnosis301::fsteering_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  Vcu_vehicle_diagnosis_301::Fsteering_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Fsteering_stateType>(x);
  return ret;
}

// config detail: {'bit': 7, 'enum': {0: 'DBSF_STATE_DBSF_OK', 1: 'DBSF_STATE_DBSF_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'dbsf_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Dbsf_stateType Vcuvehiclediagnosis301::dbsf_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(7, 1);

  Vcu_vehicle_diagnosis_301::Dbsf_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Dbsf_stateType>(x);
  return ret;
}

// config detail: {'bit': 5, 'enum': {0: 'REMOTE_STATE_RMOT_OK', 1: 'REMOTE_STATE_RMOT_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'remote_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Remote_stateType Vcuvehiclediagnosis301::remote_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 1);

  Vcu_vehicle_diagnosis_301::Remote_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Remote_stateType>(x);
  return ret;
}

// config detail: {'bit': 0, 'enum': {0: 'EMERGENCY_BUTTON_STATE_EMEBUT_ON', 1: 'EMERGENCY_BUTTON_STATE_EMEBUT_OFF'}, 'is_signed_var': False, 'len': 1, 'name': 'emergency_button_state', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcu_vehicle_diagnosis_301::Emergency_button_stateType Vcuvehiclediagnosis301::emergency_button_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 1);

  Vcu_vehicle_diagnosis_301::Emergency_button_stateType ret =  static_cast<Vcu_vehicle_diagnosis_301::Emergency_button_stateType>(x);
  return ret;
}
}  // namespace ch
}  // namespace canbus
}  // namespace apollo
