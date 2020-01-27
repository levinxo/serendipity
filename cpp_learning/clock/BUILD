load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "clock",
    srcs = ["clock.cpp","util.cpp"],
    hdrs = ["clock.h","util.h"],
)

cc_binary(
    name = "test-clock",
    srcs = ["main.cpp"],
    deps = [
        ":clock",
    ],
)
