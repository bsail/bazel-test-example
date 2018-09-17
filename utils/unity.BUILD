# Simple Unit Testing for C
# https://github.com/ThrowTheSwitch/Unity/archive/v2.4.1.zip
# LICENSE: MIT

#VERSION = "Unity_2_4_1"

cc_library(
  name = "unity",
  srcs = [
    "src/unity.c", 
    "src/unity_internals.h",
  ],
  hdrs = ["src/unity.h"],
  visibility = ["//visibility:public"],
)

cc_library(
    name = "unity_framework",
    hdrs = ["extras/fixture/src/unity_fixture.h"],
    srcs = [
      "extras/fixture/src/unity_fixture.c",
      "extras/fixture/src/unity_fixture_internals.h",
      "extras/fixture/src/unity_fixture_malloc_overrides.h",
    ],
    deps = [":unity"],
    copts = ["-Iexternal/unity/src/"],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "runner_generator",
    srcs = [
      "auto/generate_test_runner.rb",
    ],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "type_sanitizer",
    srcs = [
      "auto/type_sanitizer.rb",
    ],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "readme",
    srcs = ["README.md"],
    path = ".",
    visibility = ["//visibility:public"],
)
