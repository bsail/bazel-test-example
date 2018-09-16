load("@avr_tools//tools/avr:hex.bzl", "hex", "eeprom", "listing")

config_setting(
    name = "avr",
    values = {
        "cpu": "avr",
    },
)

cc_test(
    name = "example_unity_test",
    srcs = ["example_test.c"],
    copts = [
        "-Iexternal/unity/src/",
        "-Iexternal/unity/extras/fixture/src/"
    ],
    linkopts = select({
        ":avr": ["-mmcu=$(MCU)"],
        "//conditions:default": [],
    }),
    size = "small",
    deps = [
        "@unity//:unity_framework",
        "//src:example",
    ],
)

cc_test(
    name = "example_gtest_test",
    srcs = ["example_gtest.cc"],
    copts = ["-Iexternal/gtest/include"],
#    linkopts = select({
#        ":avr": ["-mmcu=$(MCU)"],
#        "//conditions:default": [],
#    }),
    size = "small",
    deps = [
        "@gtest//:gtest",
        "@gtest//:gtest_main", # Only if hello_test.cc has no main()
        "@fff//:fff",
        "//src:example",
    ],
)
