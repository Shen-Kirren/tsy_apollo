load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "canbus_ch_protocol",
    deps = [
        ":iecu_control_flag_501",
        ":iecu_control_steering_502",
        ":iecu_control_ibc_503",
        ":iecu_control_power_504",
        ":iecu_control_distributed_505",
        ":dbsf_status_142",
        ":epsf_status_401",
        ":mcufl_drive_motor_feedback_msg_60",
        ":mcufl_torque_feedback_10",
        ":mcufr_drive_motor_feedback_msg_70",
        ":mcufr_torque_feedback_20",
        ":mcurl_drive_motor_feedback_msg_80",
        ":mcurl_torque_feedback_30",
        ":mcurr_drive_motor_feedback_msg_90",
        ":mcurr_torque_feedback_40",
        ":vcu_vehicle_diagnosis_301",
        ":vcu_vehicle_status_1_303",
        ":vcu_vehicle_status_2_304",
        ":vcu_vehicle_status_3_305",
        ":remote_control_io_10a",
    ],
)

cc_library(
    name = "iecu_control_flag_501",
    srcs = ["iecu_control_flag_501.cc"],
    hdrs = ["iecu_control_flag_501.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "iecu_control_steering_502",
    srcs = ["iecu_control_steering_502.cc"],
    hdrs = ["iecu_control_steering_502.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "iecu_control_ibc_503",
    srcs = ["iecu_control_ibc_503.cc"],
    hdrs = ["iecu_control_ibc_503.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "iecu_control_power_504",
    srcs = ["iecu_control_power_504.cc"],
    hdrs = ["iecu_control_power_504.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "iecu_control_distributed_505",
    srcs = ["iecu_control_distributed_505.cc"],
    hdrs = ["iecu_control_distributed_505.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)


cc_library(
    name = "epsf_status_401",
    srcs = ["epsf_status_401.cc"],
    hdrs = ["epsf_status_401.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "dbsf_status_142",
    srcs = ["dbsf_status_142.cc"],
    hdrs = ["dbsf_status_142.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "mcufl_drive_motor_feedback_msg_60",
    srcs = ["mcufl_drive_motor_feedback_msg_60.cc"],
    hdrs = ["mcufl_drive_motor_feedback_msg_60.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "mcufl_torque_feedback_10",
    srcs = ["mcufl_torque_feedback_10.cc"],
    hdrs = ["mcufl_torque_feedback_10.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "mcufr_drive_motor_feedback_msg_70",
    srcs = ["mcufr_drive_motor_feedback_msg_70.cc"],
    hdrs = ["mcufr_drive_motor_feedback_msg_70.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "mcufr_torque_feedback_20",
    srcs = ["mcufr_torque_feedback_20.cc"],
    hdrs = ["mcufr_torque_feedback_20.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "mcurl_drive_motor_feedback_msg_80",
    srcs = ["mcurl_drive_motor_feedback_msg_80.cc"],
    hdrs = ["mcurl_drive_motor_feedback_msg_80.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "mcurl_torque_feedback_30",
    srcs = ["mcurl_torque_feedback_30.cc"],
    hdrs = ["mcurl_torque_feedback_30.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "mcurr_drive_motor_feedback_msg_90",
    srcs = ["mcurr_drive_motor_feedback_msg_90.cc"],
    hdrs = ["mcurr_drive_motor_feedback_msg_90.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "mcurr_torque_feedback_40",
    srcs = ["mcurr_torque_feedback_40.cc"],
    hdrs = ["mcurr_torque_feedback_40.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)


cc_library(
    name = "vcu_vehicle_diagnosis_301",
    srcs = ["vcu_vehicle_diagnosis_301.cc"],
    hdrs = ["vcu_vehicle_diagnosis_301.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "vcu_vehicle_status_1_303",
    srcs = ["vcu_vehicle_status_1_303.cc"],
    hdrs = ["vcu_vehicle_status_1_303.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "vcu_vehicle_status_2_304",
    srcs = ["vcu_vehicle_status_2_304.cc"],
    hdrs = ["vcu_vehicle_status_2_304.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "vcu_vehicle_status_3_305",
    srcs = ["vcu_vehicle_status_3_305.cc"],
    hdrs = ["vcu_vehicle_status_3_305.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)

cc_library(
    name = "remote_control_io_10a",
    srcs = ["remote_control_io_10a.cc"],
    hdrs = ["remote_control_io_10a.h"],
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/drivers/canbus/common:canbus_common",
    ],
)


cpplint()
