# bazel-test-example
Test project for Bazel build system for AVR targets with Unity tests and CMock

Based on `https://github.com/locutus3009/bazel-avr-tools` example.

The common build command is the following:
`bazel build --crosstool_top=@avr_tools//tools/avr:toolchain --distinct_host_configuration=false --define=MCU=atmega2560 --copt -DF_CPU=16000000 --cpu=avr //src:main_hex`
