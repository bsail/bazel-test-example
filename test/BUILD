genrule(
    name = "example_runner",
    srcs = ["example_test.c"],
    outs = ["example_test_Runner.c"],
    tools = [
        "@unity//:runner_generator",
        "@unity//:type_sanitizer",
    ],
    cmd = "ruby $(location @unity//:runner_generator) $< $@",
)

cc_test(
    name = "example_unity_test",
    srcs = ["example_test.c","example_test_Runner.c"],
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
