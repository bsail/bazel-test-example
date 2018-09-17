def unity_runner(name, src, **kwargs):
  """Create a Unity test runner for the src source file.

  The generated file is prefixed with 'runner_'.
  """
  native.genrule(
    name = name,
    srcs = [src],
    outs = [name+".c"],
    tools = [
        "@cmock//:create_runner",
        "@unity//:auto",
        "@unity//:readme",
    ],
    local = 1,
    cmd = "export UNITY_DIR=$$(pwd)/$$(dirname $(location @unity//:readme)) && \
      ruby $(location @cmock//:create_runner) $< $@",
    **kwargs
  )
