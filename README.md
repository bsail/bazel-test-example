# bazel-test-example
Test project for Bazel build system for AVR targets with Unity tests and CMock

Based on `https://github.com/locutus3009/bazel-avr-tools` example.

The common build command is the following:
`bazel build --config=m2560 //src:main_hex`

Run all tests:
`bazel test //test:*`
