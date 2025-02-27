workspace(name = "bazel-proto")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

# Bazel Extensions
## Bazel Skylib rules.
git_repository(
    name = "bazel_skylib",
    commit = "27d429d8d036af3d010be837cc5924de1ca8d163",
    #tag = "1.7.1",
    remote = "https://github.com/bazelbuild/bazel-skylib.git",
)
load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
bazel_skylib_workspace()

## Bazel rules...
git_repository(
    name = "platforms",
    commit = "05ec3a3df23fde62471f8288e344cc021dd87bab",
    #tag = "0.0.10",
    remote = "https://github.com/bazelbuild/platforms.git",
)

git_repository(
    name = "rules_cc",
    commit = "a1162270a0bb680190e8b4f3dab066f15a1ede6c",
    #tag = "0.1.1",
    remote = "https://github.com/bazelbuild/rules_cc.git",
)

git_repository(
    name = "rules_java",
    commit = "34d7e1bd22b31594c5de10c2d87c3dc6ab8efa74",
    #tag = "8.9.0",
    remote = "https://github.com/bazelbuild/rules_java.git",
)

load("@rules_java//java:rules_java_deps.bzl", "rules_java_dependencies")
rules_java_dependencies()

git_repository(
    name = "rules_python",
    commit = "1944874f6ba507f70d8c5e70df84622e0c783254",
    #tag = "0.40.0",
    remote = "https://github.com/bazelbuild/rules_python.git",
)

load("@rules_python//python:repositories.bzl", "py_repositories")
py_repositories()

git_repository(
    name = "rules_proto",
    commit = "4904e1ca79182d5a3779ecbd23273285ccd70e5c",
    #tag = "7.1.0",
    remote = "https://github.com/bazelbuild/rules_proto.git",
)

## Abseil-cpp
git_repository(
    name = "com_google_absl",
    commit = "4447c7562e3bc702ade25105912dce503f0c4010",
    #tag = "20240722.0",
    patches = ["//patches:abseil-cpp-20240722.0.patch"],
    patch_args = ["-p1"],
    remote = "https://github.com/abseil/abseil-cpp.git",
)

## Protobuf
# proto_library and cc_proto_library rules implicitly
# depend on @com_google_protobuf for protoc and proto runtimes.
git_repository(
    name = "com_google_protobuf",
    patches = ["//patches:protobuf-v29.3.patch"],
    patch_args = ["-p1"],
    commit = "b407e8416e3893036aee5af9a12bd9b6a0e2b2e6",
    #tag = "v29.3",
    remote = "https://github.com/protocolbuffers/protobuf.git",
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

## Testing
git_repository(
    name = "com_google_googletest",
    commit = "b514bdc898e2951020cbdca1304b75f5950d1f59",
    #tag = "v1.15.2",
    remote = "https://github.com/google/googletest.git",
)
