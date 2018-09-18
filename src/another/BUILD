load("@avr_tools//tools/avr:hex.bzl", "hex", "eeprom", "listing")
load("@utils//:unity_runner_generator.bzl", "cmock_generate")
load("@utils//:custom_macro.bzl", "custom_cc_library")
load("@utils//:custom_macro.bzl", "custom_cc_library_mock")

LIBRARY_NAME = "another"

config_setting(
    name = "avr",
    values = {
        "cpu": "avr",
    },
)

custom_cc_library(
    name = LIBRARY_NAME,
    srcs = glob(
        ["src/*"],
    ),
    hdr = "inc/"+LIBRARY_NAME+".h",
    visibility = ["//test:__pkg__","//src:__pkg__"],
)

filegroup(
    name = LIBRARY_NAME+"_header",
    srcs = ["inc/"+LIBRARY_NAME+".h"],
)

cmock_generate(
    prefix = LIBRARY_NAME,
    src = ":"+LIBRARY_NAME+"_header",
)

custom_cc_library_mock(
    name = LIBRARY_NAME,
    hdr = ":"+LIBRARY_NAME+"_header",
    deps = [],
    visibility = ["//test:__pkg__","//src:__pkg__"],
)
