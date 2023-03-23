workspace(name = "org_mizux_bazelproto")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

# Bazel Extensions
## Bazel Skylib rules.
git_repository(
    name = "bazel_skylib",
    tag = "1.4.1",
    remote = "https://github.com/bazelbuild/bazel-skylib.git",
)
load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
bazel_skylib_workspace()

## Bazel Platforms rules.
git_repository(
    name = "platforms",
    tag = "0.0.6",
    remote = "https://github.com/bazelbuild/platforms.git",
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
    tag = "v1.2.11",
    #patches = ["//patches:zlib.patch"],
    #patch_args = ["-p1"],
    remote = "https://github.com/madler/zlib.git",
)

## Re2
git_repository(
    name = "com_google_re2",
    tag = "2022-04-01",
    patches = ["//patches:re2-2022-02-01.patch"],
    patch_args = ["-p1"],
    remote = "https://github.com/google/re2.git",
)

## Abseil-cpp
git_repository(
    name = "com_google_absl",
    tag = "20230125.0",
    #patches = ["//patches:abseil-cpp-20230125.0.patch"],
    #patch_args = ["-p1"],
    remote = "https://github.com/abseil/abseil-cpp.git",
)

## Protobuf
git_repository(
    name = "com_google_protobuf",
    tag = "v22.2",
    patches = ["//patches:protobuf-v22.2.patch"],
    patch_args = ["-p1"],
    remote = "https://github.com/protocolbuffers/protobuf.git",
)
# Load common dependencies.
load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

## Testing
git_repository(
    name = "com_google_googletest",
    commit = "e2239ee", # release-1.11.0
    remote = "https://github.com/google/googletest.git",
)
