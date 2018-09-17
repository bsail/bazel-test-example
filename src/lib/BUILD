load("@avr_tools//tools/avr:hex.bzl", "hex", "eeprom", "listing")
load("//utils:unity_runner_generator.bzl", "cmock_generate")

config_setting(
    name = "avr",
    values = {
        "cpu": "avr",
    },
)

cc_library(
    name = "library",
    srcs = ["src/library.c"],
    hdrs = ["inc/library.h"],
    copts = select({
        ":avr": ["-mmcu=$(MCU)"],
        "//conditions:default": [],
    }),
    includes = [
        "./inc/",
        ],
    linkopts = select({
        ":avr": ["-mmcu=$(MCU)"],
        "//conditions:default": [],
    }),
    visibility = ["//test:__pkg__","//src:__pkg__"],
)

filegroup(
    name = "library_header",
    srcs = ["inc/library.h"],
    visibility = ["//utils:__pkg__"],
)

cmock_generate(
    prefix = "library",
    src = ":library_header",
)

cc_library(
    name = "mock_library",
    srcs = [
        "src/mock_library.c",
        ],
    hdrs = [
        "inc/mock_library.h",
        ":library_header",
        ],
    includes = [
        "./inc/",
        ],
    copts = [
        "-Iexternal/unity/src/",
        "-Iexternal/unity/extras/fixture/src/",
        "-Iexternal/cmock/src/",
        "-Isrc/lib/inc/",
    ],
    deps = [
        #"@unity//:unity",
        #"@unity//:unity_framework",
        "@cmock//:cmock",
    ],
    visibility = ["//test:__pkg__","//src:__pkg__"],
)