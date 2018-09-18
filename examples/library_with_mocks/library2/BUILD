################################################################################
################################################################################
################################################################################
##                                                                            ##
##                         Sample library declaration                         ##
##                            Nikolay Nerovny, 2018                           ##
##                                                                            ##
################################################################################
################################################################################
################################################################################
## 
## Typical directory structure for a library named 'library':
## /
## - BUILD - this file (Bazel build system package declaration)
## - inc/
## |    - library.h - main external interface for this library 
## |    |              suitable for mocking
## |    - **.h - additional headers
## - src/
## |    - **.c - library source files
## - test/
##      - library_test.c - main test source file for Unity tests with CMock
##      - **.c - additional test sources for Unity tests with CMock
##      - **.cc - test source files for GTest with FFF
## 
## Generated rules:
## :library - main rule to use in target build, Unity tests without mocking,
##            GTest with or without FFF
## :mock_library - rule to use this library in Unity/CMock tests in different
##                 packages.
##                 User have to add this rule with corresponding path or
##                 search rule to 'deps' definition and include mock_library.h
##                 in testing file.
## :library_unity_test - rule to test this library using Unity tests with CMock
## :library_gtest_test - rule to test this library using GTest tests with FFF
##
################################################################################


################################################################################
##                                                                            ##
##                          General library settings                          ##
##                                                                            ##
################################################################################

LIBRARY_NAME = "library2"
LIBRARY_VISIBILITY = []
LIBRARY_DEPS = ["//library1:library1"]

################################################################################
##                                                                            ##
##              Library testing settings. Unity tests with CMock              ##
##                                                                            ##
################################################################################

LIBRARY_TEST_UNITY_SIZE = "small"
LIBRARY_TEST_UNITY_DEPS = ["//library1:mock_library1"]
LIBRARY_CMOCK_DEPS = []

################################################################################
##                                                                            ##
##                  Library testing settings. GTest with FFF                  ##
##                                                                            ##
################################################################################

LIBRARY_TEST_GTEST_SIZE = "small"
LIBRARY_TEST_GTEST_DEPS = LIBRARY_DEPS

################################################################################
################################################################################
################################################################################
##                                                                            ##
## For the ordinary usage, the user may not change the following declarations ##
## However, if he or she wants to disable Unity tests of GTests, one may      ##
## comment out the corresponding section                                      ##
##                                                                            ##
################################################################################
################################################################################
################################################################################

################################################################################
##                                                                            ##
##                   Declaration of helper strings and macro                  ##
##                                                                            ##
################################################################################

load("@avr_tools//tools/avr:hex.bzl", "hex", "eeprom", "listing")
load("@utils//:unity_runner_generator.bzl", "cmock_generate")
load("@utils//:custom_macro.bzl", "custom_cc_library")
load("@utils//:custom_macro.bzl", "custom_cc_library_mock")
load("@utils//:unity_runner_generator.bzl", "unity_runner")
load("@utils//:unity_runner_generator.bzl", "UNITY_COPTS")
load("@utils//:unity_runner_generator.bzl", "UNITY_DEPS")
load("@utils//:unity_runner_generator.bzl", "GTEST_COPTS")
load("@utils//:unity_runner_generator.bzl", "GTEST_DEPS")

################################################################################
##                                                                            ##
##                                     Rules                                  ##
##                                                                            ##
################################################################################

config_setting(
    name = "avr",
    values = {
        "cpu": "avr",
    },
)

filegroup(
    name = LIBRARY_NAME+"_header",
    srcs = ["inc/"+LIBRARY_NAME+".h"],
)

################################################################################
##                                                                            ##
##                            Main library rule                               ##
##                                                                            ##
################################################################################

custom_cc_library(
    name = LIBRARY_NAME,
    srcs = glob(
        ["src/*"],
    ) + glob(
        ["inc/*"],
    ),
    hdr = LIBRARY_NAME+"_header",
    deps = LIBRARY_DEPS,
    visibility = LIBRARY_VISIBILITY,
)

custom_cc_library(
    name = LIBRARY_NAME+"_for_mocking",
    srcs = glob(
        ["src/*"],
    ),
    hdr = LIBRARY_NAME+"_header",
    deps = LIBRARY_TEST_UNITY_DEPS,
    testonly = True,
)

################################################################################
##                                                                            ##
##           Library rule to use in CMock tests from different packages       ##
##                                                                            ##
################################################################################

cmock_generate(
    prefix = LIBRARY_NAME,
    src = ":"+LIBRARY_NAME+"_header",
)

custom_cc_library_mock(
    name = LIBRARY_NAME,
    hdr = LIBRARY_NAME+"_header",
    deps = LIBRARY_CMOCK_DEPS,
    visibility = LIBRARY_VISIBILITY,
    testonly = True,
)

################################################################################
##                                                                            ##
##       Library rule to test using Unity testing framework with CMock        ##
##                                                                            ##
################################################################################

LIBRARY_TEST_UNITY_MAIN_SOURCE = LIBRARY_NAME+"_test.c"

unity_runner(
    name = "runner_"+LIBRARY_NAME+"_test",
    src = "test/"+LIBRARY_TEST_UNITY_MAIN_SOURCE,
)

cc_test(
    name = LIBRARY_NAME+"_unity_test",
    srcs = [
        "test/"+LIBRARY_TEST_UNITY_MAIN_SOURCE,
        "runner_"+LIBRARY_NAME+"_test.c",
    ] + glob(
        ["test/*.c"],
        exclude = ["test/"+LIBRARY_TEST_UNITY_MAIN_SOURCE]
    ),
    copts = UNITY_COPTS,
    size = LIBRARY_TEST_UNITY_SIZE,
    deps = [
        ":"+LIBRARY_NAME+"_for_mocking",
    ] + UNITY_DEPS + LIBRARY_TEST_UNITY_DEPS,
)

################################################################################
##                                                                            ##
##         Library rule to test using GTest testing framework with FFF        ##
##                                                                            ##
################################################################################

cc_test(
    name = LIBRARY_NAME+"_gtest_test",
    srcs = glob(
        ["test/*.cc"],
    ),
    copts = GTEST_COPTS,
    size = LIBRARY_TEST_GTEST_SIZE,
    deps = [
        ":"+LIBRARY_NAME,
    ] + GTEST_DEPS + LIBRARY_TEST_GTEST_DEPS,
)
################################################################################
