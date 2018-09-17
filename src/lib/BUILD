load("@avr_tools//tools/avr:hex.bzl", "hex", "eeprom", "listing")
load("//utils:cmock_mock_generator.bzl", "cmock_generator_source")
load("//utils:cmock_mock_generator.bzl", "cmock_generator_header")

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

cmock_generator_source(
    prefix = "library",
    src = ":library_header",
)

cmock_generator_header(
    prefix = "library",
    src = ":library_header",
)

cc_library(
    name = "mock_library",
    srcs = [
        "mock_library.c",
        "mock_library.h",
    ],
    hdrs = [":library_header"],
    copts = [
        "-Iexternal/unity/src/",
        "-Iexternal/unity/extras/fixture/src/",
        "-Iexternal/cmock/src/",
        "-Isrc/lib/",
    ],
    deps = [
        "@unity//:unity",
        "@unity//:unity_framework",
        "@cmock//:cmock",
    ],
    visibility = ["//test:__pkg__"],
)
