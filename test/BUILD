load("@avr_tools//tools/avr:hex.bzl", "hex", "eeprom", "listing")


# Written for Adafruit Trinket (ATTiny 85)
#
# Functions:
#
# 1. Idle state: output off
# 2. begin idle timer
# 3. Input pin goes active:
#      a. if idle timer > X
#         delay for x seconds
#      b. disable idle timer
#      c. enable output pin
#      d. enable and reset shutdown timer
# 4. When shutdown timer expires, output is disabled
#

config_setting(
    name = "avr",
    values = {
        "cpu": "avr",
    },
)

cc_test(
    name = "example_test",
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
        #"//utils/unity:unity_framework",
    ],
)
