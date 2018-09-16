def unity_runner(name, src, **kwargs):
  """Create a Unity test runner for the src source file.

  The generated file is prefixed with 'Runner_'.
  """
  native.genrule(
    name = name,
    srcs = [src],
    outs = [name],
    tools = [
        "@unity//:runner_generator",
        "@unity//:type_sanitizer",
    ],
    cmd = "ruby $(location @unity//:runner_generator) $< $@",
    **kwargs
  )
