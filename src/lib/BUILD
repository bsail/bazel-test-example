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
