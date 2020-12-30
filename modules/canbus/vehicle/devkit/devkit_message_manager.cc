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

#include "modules/canbus/vehicle/devkit/devkit_message_manager.h"

#include "modules/canbus/vehicle/devkit/protocol/iecu_control_distributed_505.h"
#include "modules/canbus/vehicle/devkit/protocol/iecu_control_flag_501.h"
#include "modules/canbus/vehicle/devkit/protocol/iecu_control_ibc_503.h"
#include "modules/canbus/vehicle/devkit/protocol/iecu_control_power_504.h"
#include "modules/canbus/vehicle/devkit/protocol/iecu_control_steering_502.h"

#include "modules/canbus/vehicle/devkit/protocol/dbsf_status_142.h"
#include "modules/canbus/vehicle/devkit/protocol/epsf_status_401.h"
#include "modules/canbus/vehicle/devkit/protocol/mcufl_drive_motor_feedback_msg_60.h"
#include "modules/canbus/vehicle/devkit/protocol/mcufl_torque_feedback_10.h"
#include "modules/canbus/vehicle/devkit/protocol/mcufr_drive_motor_feedback_msg_70.h"
#include "modules/canbus/vehicle/devkit/protocol/mcufr_torque_feedback_20.h"
#include "modules/canbus/vehicle/devkit/protocol/mcurl_drive_motor_feedback_msg_80.h"
#include "modules/canbus/vehicle/devkit/protocol/mcurl_torque_feedback_30.h"
#include "modules/canbus/vehicle/devkit/protocol/mcurr_drive_motor_feedback_msg_90.h"
#include "modules/canbus/vehicle/devkit/protocol/mcurr_torque_feedback_40.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_vehicle_diagnosis_301.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_vehicle_status_1_303.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_vehicle_status_2_304.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_vehicle_status_3_305.h"
/*
#include "modules/canbus/vehicle/devkit/protocol/epb_status_375_375.h"
#include "modules/canbus/vehicle/devkit/protocol/epsr_status_111.h"
#include "modules/canbus/vehicle/devkit/protocol/imu_acceleration_181.h"
#include "modules/canbus/vehicle/devkit/protocol/imu_angular_281.h"
#include "modules/canbus/vehicle/devkit/protocol/imu_euler_381.h"
#include "modules/canbus/vehicle/devkit/protocol/remote_control_io_10a.h"
#include "modules/canbus/vehicle/devkit/protocol/remote_control_shake_2_10b.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_dbsf_request_154.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_epb_request_310_310.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_epsf_control_request_469.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_epsr_control_request_101.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_mcufl_request_1_160.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_mcufr_request_1_170.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_mcurl_request_1_180.h"
#include "modules/canbus/vehicle/devkit/protocol/vcu_mcurr_request_1_190.h"
*/
//#include "modules/canbus/vehicle/devkit/protocol/vector__independent_sig_msg_c0000000.h"

namespace apollo {
namespace canbus {
namespace devkit {

DevkitMessageManager::DevkitMessageManager() {
  // Control Messages
  AddSendProtocolData<Iecucontroldistributed505, true>();
  AddSendProtocolData<Iecucontrolflag501, true>();
  AddSendProtocolData<Iecucontrolibc503, true>();
  AddSendProtocolData<Iecucontrolpower504, true>();
  AddSendProtocolData<Iecucontrolsteering502, true>();

  // Report Messages
  AddRecvProtocolData<Mcufltorquefeedback10, true>();
  AddRecvProtocolData<Mcufrtorquefeedback20, true>();
  AddRecvProtocolData<Mcurltorquefeedback30, true>();
  AddRecvProtocolData<Mcurrtorquefeedback40, true>();
  AddRecvProtocolData<Mcufldrivemotorfeedbackmsg60, true>();
  AddRecvProtocolData<Mcufrdrivemotorfeedbackmsg70, true>();
  AddRecvProtocolData<Mcurldrivemotorfeedbackmsg80, true>();
  AddRecvProtocolData<Mcurrdrivemotorfeedbackmsg90, true>();
  AddRecvProtocolData<Vcuvehiclediagnosis301, true>();
  AddRecvProtocolData<Vcuvehiclestatus1303, true>();
  AddRecvProtocolData<Vcuvehiclestatus2304, true>();
  AddRecvProtocolData<Vcuvehiclestatus3305, true>();
  AddRecvProtocolData<Dbsfstatus142, true>();
  AddRecvProtocolData<Epsfstatus401, true>();
  
  //not use
  /*
  AddRecvProtocolData<Epbstatus375375, true>();
  AddRecvProtocolData<Epsrstatus111, true>();
  AddRecvProtocolData<Imuacceleration181, true>();
  AddRecvProtocolData<Imuangular281, true>();
  AddRecvProtocolData<Imueuler381, true>();
  AddRecvProtocolData<Mcurrtorquefeedback40, true>();
  AddRecvProtocolData<Remotecontrolio10a, true>();
  AddRecvProtocolData<Remotecontrolshake210b, true>();
  AddRecvProtocolData<Vcudbsfrequest154, true>();
  AddRecvProtocolData<Vcuepbrequest310310, true>();
  AddRecvProtocolData<Vcuepsfcontrolrequest469, true>();
  AddRecvProtocolData<Vcuepsrcontrolrequest101, true>();
  AddRecvProtocolData<Vcumcuflrequest1160, true>();
  AddRecvProtocolData<Vcumcufrrequest1170, true>();
  AddRecvProtocolData<Vcumcurlrequest1180, true>();
  AddRecvProtocolData<Vcumcurrrequest1190, true>();
  AddRecvProtocolData<Vectorindependentsigmsgc0000000, true>();
  */
}


DevkitMessageManager::~DevkitMessageManager() {}

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo
