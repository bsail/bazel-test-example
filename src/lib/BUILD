load("@avr_tools//tools/avr:hex.bzl", "hex", "eeprom", "listing")
load("//utils:unity_runner_generator.bzl", "cmock_generator")

config_setting(
    name = "avr",
    values = {
        "cpu": "avr",
    },
)

cc_library(
    name = "library",
    srcs = ["library.c"],
    hdrs = ["library.h"],
    copts = select({
        ":avr": ["-mmcu=$(MCU)"],
        "//conditions:default": [],
    }),
    linkopts = select({
        ":avr": ["-mmcu=$(MCU)"],
        "//conditions:default": [],
    }),
    visibility = ["//test:__pkg__","//src:__pkg__"],
)

filegroup(
    name = "library_header",
    srcs = ["library.h"],
    #visibility = ["//utils:__pkg__"],
)

cmock_generator(
    prefix = "library",
    src = ":library_header",
    type = "h",
)

cmock_generator(
    prefix = "library",
    src = ":library_header",
    type = "c",
)

cc_library(
    name = "mock_library",
    srcs = [
        "mock_library.c",
        "library.h",
        ],
    hdrs = [
        "mock_library.h",
        ],
    copts = [
        "-Iexternal/unity/src/",
        "-Iexternal/unity/extras/fixture/src/",
        "-Iexternal/cmock/src/",
    ],
    deps = [
        "@unity//:unity",
        "@unity//:unity_framework",
        "@cmock//:cmock",
    ],
    visibility = ["//test:__pkg__"],
)
