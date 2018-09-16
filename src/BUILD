load("@avr_tools//tools/avr:hex.bzl", "hex", "eeprom", "listing")

config_setting(
    name = "avr",
    values = {
        "cpu": "avr",
    },
)

cc_binary(
    name = "main",
    srcs = ["main.c"],
    deps = [
        ":example",
    ],
    copts = select({
        ":avr": ["-mmcu=$(MCU)"],
        "//conditions:default": [],
    }),
    linkopts = select({
        ":avr": ["-mmcu=$(MCU)"],
        "//conditions:default": [],
    }),
)

cc_library(
    name = "example",
    srcs = ["example.c"],
    hdrs = ["example.h"],
    copts = select({
        ":avr": ["-mmcu=$(MCU)"],
        "//conditions:default": [],
    }),
    linkopts = select({
        ":avr": ["-mmcu=$(MCU)"],
        "//conditions:default": [],
    }),
    visibility = ["//test:__pkg__"],
)

hex(
    name = "main_hex",
    src = ":main"
)

listing(
    name = "main_listing",
    src = ":main"
)

