workspace(name = "bazel-proto")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

################################################################################
#
# WORKSPACE is being deprecated in favor of the new Bzlmod dependency system.
# It will be removed at some point in the future.
#
################################################################################

# Bazel Extensions
## Needed for Abseil.
git_repository(
    name = "bazel_skylib",
    commit = "56a2abbaf131332835ab2721a258ea3c763a7178",
    #tag = "1.8.1",
    remote = "https://github.com/bazelbuild/bazel-skylib.git",
)
load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
bazel_skylib_workspace()

git_repository(
    name = "bazel_features",
    commit = "3f23ff44ff85416d96566bee8e407694cdb6f1f8",
    #tag = "v1.32.0",
    remote = "https://github.com/bazel-contrib/bazel_features.git",
)
load("@bazel_features//:deps.bzl", "bazel_features_deps")
bazel_features_deps()

## Bazel rules.
git_repository(
    name = "platforms",
    commit = "ab99943ab6bed53cff461a3afa99fc79d31e4351",
    #tag = "1.0.0",
    remote = "https://github.com/bazelbuild/platforms.git",
)

git_repository(
    name = "rules_cc",
    commit = "cbee84ad7f583049823f3d1497aab1264cf94f26",
    #tag = "0.1.4",
    remote = "https://github.com/bazelbuild/rules_cc.git",
)

git_repository(
    name = "rules_proto",
    commit = "4904e1ca79182d5a3779ecbd23273285ccd70e5c",
    #tag = "7.1.0",
    remote = "https://github.com/bazelbuild/rules_proto.git",
    #repo_mapping = {"@protobuf": "@com_google_protobuf"},
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies")
rules_proto_dependencies()
load("@rules_proto//proto:toolchains.bzl", "rules_proto_toolchains")
rules_proto_toolchains()

## Abseil-cpp
git_repository(
    name = "abseil-cpp",
    commit = "d38452e1ee03523a208362186fd42248ff2609f6",
    #tag = "20250814.1",
    remote = "https://github.com/abseil/abseil-cpp.git",
)

## Re2
git_repository(
    name = "re2",
    commit = "6dcd83d60f7944926bfd308cc13979fc53dd69ca",
    #tag = "2024-07-02",
    remote = "https://github.com/google/re2.git",
    #repo_mapping = {"@abseil-cpp": "@com_google_absl"},
)

## Protobuf
# proto_library and cc_proto_library rules implicitly
# depend on @com_google_protobuf for protoc and proto runtimes.
git_repository(
    name = "com_google_protobuf",
    commit = "74211c0dfc2777318ab53c2cd2c317a2ef9012de",
    #tag = "v31.1",
    remote = "https://github.com/protocolbuffers/protobuf.git",
)
load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

# Testing
## Googletest
git_repository(
    name = "googletest",
    commit = "52eb8108c5bdec04579160ae17225d66034bd723",
    #tag = "v1.17.0",
    remote = "https://github.com/google/googletest.git",
)
