load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "stack",
    srcs = ["stack.cc"],
    hdrs = ["stack.h"],
)

cc_binary(
    name = "test-stack",
    srcs = ["test-stack.cc"],
    deps = [
        ":stack",
    ],
)
