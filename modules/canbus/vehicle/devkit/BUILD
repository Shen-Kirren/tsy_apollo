load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "devkit_vehicle_factory",
    srcs = [
        "devkit_vehicle_factory.cc",
    ],
    hdrs = [
        "devkit_vehicle_factory.h",
    ],
    deps = [
        ":devkit_controller",
        ":devkit_message_manager",
        "//modules/canbus/vehicle:abstract_vehicle_factory",
    ],
)

cc_library(
    name = "devkit_message_manager",
    srcs = [
        "devkit_message_manager.cc",
    ],
    hdrs = [
        "devkit_message_manager.h",
    ],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle/devkit/protocol:canbus_devkit_protocol",
    ],
)

cc_library(
    name = "devkit_controller",
    srcs = [
        "devkit_controller.cc",
    ],
    hdrs = [
        "devkit_controller.h",
    ],
    deps = [
        ":devkit_message_manager",
        "//modules/drivers/canbus/can_comm:can_sender",
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle:vehicle_controller_base",
        "//modules/canbus/vehicle/devkit/protocol:canbus_devkit_protocol",
    ],
)

cpplint()
