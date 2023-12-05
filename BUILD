load("@rules_proto//proto:defs.bzl", "proto_library")
package(default_visibility = ["//visibility:public"])

proto_library(
    name = "paxos_msg_proto_lib",
    srcs = [
        "src/comm/paxos_msg.proto",
    ],
)
cc_proto_library(
    name = "paxos_msg_proto_cc",
    deps = [
        ":paxos_msg_proto_lib",
    ],
)

proto_library(
    name = "master_sm_proto_lib",
    srcs = [
        "src/master/master_sm.proto",
    ],
)
cc_proto_library(
    name = "master_sm_proto_cc",
    deps = [
        ":master_sm_proto_lib",
    ],
)

cc_library(
    name = "phxpaxos",
    srcs = glob([
        "src/**/*.cpp",
    ]),
    hdrs = glob([ 
        "src/**/*.h",
        "include/**/*.h",
    ]),
    includes = [
        "./include/",
        "./src/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_leveldb//:leveldb",
        "@com_google_protobuf//:protobuf",
        ":paxos_msg_proto_cc",
        ":master_sm_proto_cc",
    ],
    copts = [
    ],
    defines = [
    ],
)

cc_library(
    name = "phxpaxos_plugin",
    srcs = glob([
        "plugin/logger_google/*.cpp",
        "plugin/monitor/*.cpp",
    ]),
    hdrs = glob([ 
        "plugin/**/*.h",
    ]),
    includes = [
        "plugin/include/",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_glog//:glog",
        ":phxpaxos",
    ],
    copts = [
    ],
    defines = [
    ],
)


cc_binary(
    name = "phxpaxos_test",
    srcs = [
        "sample/phxecho/echo_server.cpp",
        "sample/phxecho/echo_sm.cpp",
        "sample/phxecho/main.cpp",
        "sample/phxecho/echo_server.h",
        "sample/phxecho/echo_sm.h",
    ],
    deps = [
        ":phxpaxos",
        ":phxpaxos_plugin",
    ]
)