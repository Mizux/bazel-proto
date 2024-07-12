workspace(name = "org_mizux_bazelproto")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

# Bazel Extensions
## Bazel Skylib rules.
git_repository(
    name = "bazel_skylib",
    tag = "1.7.1",
    remote = "https://github.com/bazelbuild/bazel-skylib.git",
)
load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
bazel_skylib_workspace()

## Bazel rules.
git_repository(
    name = "platforms",
    tag = "0.0.10",
    remote = "https://github.com/bazelbuild/platforms.git",
)

git_repository(
    name = "rules_cc",
    tag = "0.0.9",
    remote = "https://github.com/bazelbuild/rules_cc.git",
)

git_repository(
    name = "rules_proto",
    tag = "5.3.0-21.7",
    remote = "https://github.com/bazelbuild/rules_proto.git",
)

# Dependencies
## ZLIB
new_git_repository(
    name = "zlib",
    build_file = "@com_google_protobuf//:third_party/zlib.BUILD",
    tag = "v1.3.1",
    remote = "https://github.com/madler/zlib.git",
)

## Abseil-cpp
git_repository(
    name = "com_google_absl",
    tag = "20240116.2",
    patches = ["//patches:abseil-cpp-20240116.2.patch"],
    patch_args = ["-p1"],
    remote = "https://github.com/abseil/abseil-cpp.git",
)

## Re2
git_repository(
    name = "com_google_re2",
    tag = "2024-04-01",
    remote = "https://github.com/google/re2.git",
    repo_mapping = {"@abseil-cpp": "@com_google_absl"},
)

## Protobuf
# proto_library and cc_proto_library rules implicitly
# depend on @com_google_protobuf for protoc and proto runtimes.
# This statement defines the @com_google_protobuf repo.
git_repository(
    name = "com_google_protobuf",
    patches = ["//patches:protobuf-v27.2.patch"],
    patch_args = ["-p1"],
    tag = "v27.2",
    remote = "https://github.com/protocolbuffers/protobuf.git",
)
# Load common dependencies.
load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

## Testing
git_repository(
    name = "com_google_googletest",
    tag = "v1.14.0",
    remote = "https://github.com/google/googletest.git",
)
