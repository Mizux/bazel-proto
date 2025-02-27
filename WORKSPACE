workspace(name = "org_mizux_bazelproto")

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
    tag = "0.1.1",
    remote = "https://github.com/bazelbuild/rules_cc.git",
)

git_repository(
    name = "rules_python",
    commit = "1944874f6ba507f70d8c5e70df84622e0c783254",
    #tag = "0.40.0",
    remote = "https://github.com/bazelbuild/rules_python.git",
)

load("@rules_python//python:repositories.bzl", "py_repositories")
py_repositories()

git_repository(
    name = "rules_java",
    tag = "8.9.0",
    remote = "https://github.com/bazelbuild/rules_java.git",
)

load("@rules_java//java:rules_java_deps.bzl", "rules_java_dependencies")
rules_java_dependencies()

git_repository(
    name = "rules_proto",
    tag = "7.1.0",
    remote = "https://github.com/bazelbuild/rules_proto.git",
)


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
    tag = "20240722.0",
    patches = ["//patches:abseil-cpp-20240722.0.patch"],
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
git_repository(
    name = "com_google_protobuf",
    patches = ["//patches:protobuf-v29.3.patch"],
    patch_args = ["-p1"],
    tag = "v29.3",
    remote = "https://github.com/protocolbuffers/protobuf.git",
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

## Testing
git_repository(
    name = "com_google_googletest",
    tag = "v1.15.2",
    remote = "https://github.com/google/googletest.git",
)
