load("@utils//:unity_runner_generator.bzl", "unity_runner")
load("@utils//:unity_runner_generator.bzl", "UNITY_COPTS")
load("@utils//:unity_runner_generator.bzl", "UNITY_DEPS")
load("@utils//:unity_runner_generator.bzl", "GTEST_COPTS")
load("@utils//:unity_runner_generator.bzl", "GTEST_DEPS")

unity_runner(
    name = "runner_example_test",
    src = "example_test.c",
)

cc_test(
    name = "example_unity_test",
    srcs = [
        "example_test.c",
        "runner_example_test.c",
    ],
    copts = UNITY_COPTS,
    size = "small",
    deps = [
        "//src:example_with_cmock",
        "//src/lib:mock_library",
        "//src/another:mock_another",
    ] + UNITY_DEPS,
)

cc_test(
    name = "example_gtest_test",
    srcs = ["example_gtest.cc"],
    copts = GTEST_COPTS,
    size = "small",
    deps = [
        "//src:example",
    ] + GTEST_DEPS,
)
