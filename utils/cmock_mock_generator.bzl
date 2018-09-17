def cmock_generator_source(prefix, src, **kwargs):
  """Create a Unity test runner for the src source file.

  The generated file is prefixed with 'Runner_'.
  """
  native.genrule(
    name = "source_"+prefix,
    srcs = [src],
    outs = ["mock_"+prefix+".c"],
    tools = [
        "@cmock//:cmock_rb",
        "@cmock//:lib",
        "@cmock//:config",
        "//utils/mock:cmock_config",
        "@unity//:readme",
        "@unity//:type_sanitizer",
    ],
    #local = 1,
    cmd = "mkdir mock && \
    export UNITY_DIR=$$(dirname $(location @unity//:readme)) && \
    ruby $(location @cmock//:cmock_rb) -o$(location //utils/mock:cmock_config) $< && \
    cat mock_library.c > $@",
    **kwargs
  )

def cmock_generator_header(prefix, src, **kwargs):
  """Create a Unity test runner for the src header file.

  The generated file is prefixed with 'Runner_'.
  """
  native.genrule(
    name = "header_"+prefix,
    srcs = [src],
    outs = ["mock_"+prefix+".h"],
    tools = [
        "@cmock//:cmock_rb",
        "@cmock//:lib",
        "@cmock//:config",
        "//utils/mock:cmock_config",
        "@unity//:readme",
        "@unity//:type_sanitizer",
    ],
    #local = 1,
    cmd = "mkdir mock && \
    export UNITY_DIR=$$(dirname $(location @unity//:readme)) && \
    ruby $(location @cmock//:cmock_rb) -o$(location //utils/mock:cmock_config) $< && \
    cat mock_library.h > $@",
    **kwargs
  )

