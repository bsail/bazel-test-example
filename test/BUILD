load("//utils:unity_runner_generator.bzl", "unity_runner")

unity_runner(
    name = "runner_example_test.c",
    src = "example_test.c",
)

cc_test(
    name = "example_unity_test",
    srcs = ["example_test.c","runner_example_test.c"],
    copts = [
        "-Iexternal/unity/src/",
        "-Iexternal/unity/extras/fixture/src/"
    ],
    size = "small",
    deps = [
        "@unity//:unity_framework",
        "@cmock//:cmock",
        "//src:example",
    ],
)

cc_test(
    name = "example_gtest_test",
    srcs = ["example_gtest.cc"],
    copts = ["-Iexternal/gtest/include"],
    size = "small",
    deps = [
        "@gtest//:gtest",
        "@gtest//:gtest_main", # Only if hello_test.cc has no main()
        "@fff//:fff",
        "//src:example",
    ],
)
