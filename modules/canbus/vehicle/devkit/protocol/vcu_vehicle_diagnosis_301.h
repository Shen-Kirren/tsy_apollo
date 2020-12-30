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

class Vcuvehiclediagnosis301 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Vcuvehiclediagnosis301();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'Vehicle_Diagnosis_Reserved_3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int vehicle_diagnosis_reserved_3(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'is_signed_var': False, 'len': 14, 'name': 'Vehicle_Diagnosis_Reserved_1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int vehicle_diagnosis_reserved_1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'Vehicle_Diagnosis_Reserved_2', 'offset': -0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int vehicle_diagnosis_reserved_2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 14, 'enum': {0: 'EPB_STATE_EPB_OK', 1: 'EPB_STATE_EPB_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'EPB_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Epb_stateType epb_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'enum': {0: 'VEHICLE_FAULT_GRADE_CAR_OK', 1: 'VEHICLE_FAULT_GRADE_CAR_ERR1', 2: 'VEHICLE_FAULT_GRADE_CAR_ERR2', 3: 'VEHICLE_FAULT_GRADE_CAR_ERR3'}, 'is_signed_var': False, 'len': 2, 'name': 'Vehicle_Fault_Grade', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Vehicle_fault_gradeType vehicle_fault_grade(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 13, 'enum': {0: 'R_ATTACH_SWITCH_STATE_RATCH_OK', 1: 'R_ATTACH_SWITCH_STATE_RATCH_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'R_Attach_Switch_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::R_attach_switch_stateType r_attach_switch_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 12, 'enum': {0: 'F_ATTACH_SWITCH_STATE_FATCH_OK', 1: 'F_ATTACH_SWITCH_STATE_FATCH_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'F_Attach_Switch_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::F_attach_switch_stateType f_attach_switch_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'enum': {0: 'BMS_STATE_BMS_OK', 1: 'BMS_STATE_BMS_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'BMS_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Bms_stateType bms_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 6, 'enum': {0: 'IECU_STATE_IECU_OK', 1: 'IECU_STATE_IECU_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'iECU_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Iecu_stateType iecu_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'enum': {0: 'DBSR_STATE_DBSR_OK', 1: 'DBSR_STATE_DBSR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'DBSR_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Dbsr_stateType dbsr_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 4, 'enum': {0: 'RLMOTOR_STATE_RL_OK', 1: 'RLMOTOR_STATE_RL_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'RLMotor_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Rlmotor_stateType rlmotor_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 3, 'enum': {0: 'RRMOTOR_STATE_RR_OK', 1: 'RRMOTOR_STATE_RR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'RRMotor_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Rrmotor_stateType rrmotor_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 2, 'enum': {0: 'FLMOTOR_STATE_FL_OK', 1: 'FLMOTOR_STATE_FL_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'FLMotor_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Flmotor_stateType flmotor_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 1, 'enum': {0: 'FRMOTOR_STATE_FR_OK', 1: 'FRMOTOR_STATE_FR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'FRMotor_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Frmotor_stateType frmotor_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'RSTEERING_STATE_RSTR_OK', 1: 'RSTEERING_STATE_RSTR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'RSteering_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Rsteering_stateType rsteering_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 10, 'enum': {0: 'FSTEERING_STATE_FSTR_OK', 1: 'FSTEERING_STATE_FSTR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'FSteering_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Fsteering_stateType fsteering_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'enum': {0: 'DBSF_STATE_DBSF_OK', 1: 'DBSF_STATE_DBSF_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'DBSF_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Dbsf_stateType dbsf_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 5, 'enum': {0: 'REMOTE_STATE_RMOT_OK', 1: 'REMOTE_STATE_RMOT_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'Remote_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Remote_stateType remote_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'enum': {0: 'EMERGENCY_BUTTON_STATE_EMEBUT_ON', 1: 'EMERGENCY_BUTTON_STATE_EMEBUT_OFF'}, 'is_signed_var': False, 'len': 1, 'name': 'Emergency_Button_State', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcu_vehicle_diagnosis_301::Emergency_button_stateType emergency_button_state(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo


