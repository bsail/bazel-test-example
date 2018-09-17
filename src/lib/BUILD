load("@avr_tools//tools/avr:hex.bzl", "hex", "eeprom", "listing")
load("@utils//:unity_runner_generator.bzl", "cmock_generate")
load("@utils//:custom_macro.bzl", "custom_cc_libary")
load("@utils//:custom_macro.bzl", "custom_cc_libary_mock")

LIBRARY_NAME = "library"

config_setting(
    name = "avr",
    values = {
        "cpu": "avr",
    },
)

custom_cc_libary(
    name = LIBRARY_NAME,
    srcs = ["src/library.c"],
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

custom_cc_libary_mock(
    name = LIBRARY_NAME,
    hdr = ":"+LIBRARY_NAME+"_header",
    deps = [],
    visibility = ["//test:__pkg__","//src:__pkg__"],
)
