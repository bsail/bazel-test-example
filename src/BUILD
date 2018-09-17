load("@avr_tools//tools/avr:hex.bzl", "hex", "eeprom", "listing")
load("//utils:custom_macro.bzl", "custom_cc_libary")

config_setting(
    name = "avr",
    values = {
        "cpu": "avr",
    },
)

config_setting(
    name = "use_cmock",
    define_values = {
        "cmock": "true",
    }
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

LIBRARY_NAME = "example"

custom_cc_libary(
    name = LIBRARY_NAME,
    srcs = ["example.c"],
    hdr = LIBRARY_NAME+".h",
    deps = ["//src/lib:library"],
    visibility = ["//test:__pkg__","//src:__pkg__"],
)

custom_cc_libary(
    name = LIBRARY_NAME+"_with_cmock",
    srcs = ["example.c"],
    hdr = LIBRARY_NAME+".h",
    deps = ["//src/lib:mock_library"],
    visibility = ["//test:__pkg__","//src:__pkg__"],
)

hex(
    name = "main_hex",
    src = ":main"
)

listing(
    name = "main_listing",
    src = ":main"
)
