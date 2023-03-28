Github-CI:
[![Build Status][github_linux_bazel_status]][github_linux_bazel_link]
[![Build Status][github_macos_bazel_status]][github_macos_bazel_link]
[![Build Status][github_windows_bazel_status]][github_windows_bazel_link]
[![Build Status][github_amd64_docker_bazel_status]][github_amd64_docker_bazel_link]

[github_linux_bazel_status]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_linux_bazel.yml/badge.svg
[github_linux_bazel_link]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_linux_bazel.yml
[github_macos_bazel_status]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_macos_bazel.yml/badge.svg
[github_macos_bazel_link]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_macos_bazel.yml
[github_windows_bazel_status]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_windows_bazel.yml/badge.svg
[github_windows_bazel_link]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_windows_bazel.yml
[github_amd64_docker_bazel_status]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_docker_bazel.yml/badge.svg
[github_amd64_docker_bazel_link]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_docker_bazel.yml

[![Build Status][github_linux_cmake_status]][github_linux_cmake_link]
[![Build Status][github_macos_cmake_status]][github_macos_cmake_link]
[![Build Status][github_windows_cmake_status]][github_windows_cmake_link]
[![Build Status][github_amd64_docker_cmake_status]][github_amd64_docker_cmake_link]

[github_linux_cmake_status]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_linux_cmake.yml/badge.svg
[github_linux_cmake_link]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_linux_cmake.yml
[github_macos_cmake_status]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_macos_cmake.yml/badge.svg
[github_macos_cmake_link]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_macos_cmake.yml
[github_windows_cmake_status]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_windows_cmake.yml/badge.svg
[github_windows_cmake_link]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_windows_cmake.yml
[github_amd64_docker_cmake_status]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_docker_cmake.yml/badge.svg
[github_amd64_docker_cmake_link]: https://github.com/Mizux/bazel-proto/actions/workflows/amd64_docker_cmake.yml

# Introduction

<nav for="project"> |
<a href="#requirement">Requirement</a> |
<a href="#codemap">Codemap</a> |
<a href="#dependencies">Dependencies</a> |
<a href="#build">Build</a> |
<a href="#tutorial">Tutorial</a> |
<a href="bazel/README.md">Bazel CI</a> |
<a href="cmake/README.md">CMake CI</a> |
<a href="#appendices">Appendices</a> |
<a href="#license">License</a> |
</nav>

Bazel/CMake C++ + Protobuf sample with tests and GitHub CI support.

This project should run on GNU/Linux, MacOS and Windows.

## Requirement

You'll need:

* "Bazel >= 6.0".
* "CMake >= 3.25".

## Codemap

The project layout is as follow:

* [WORKSPACE](WORKSPACE) Top-level for [Bazel](https://bazel.build) based build.

## Dependencies

To complexify a little, the CMake project is composed of three libraries (Foo, Bar and FooBar)
with the following dependencies:

```sh
Foo:
Bar:
FooBar: PUBLIC Foo PRIVATE Bar
App: PRIVATE FooBar
```

note: Since `Foo` is a public dependency of `FooBar`, then `FooBarApp` will
*see* `Foo` inlude directories

## Build

To build this example you should use:

* on UNIX:
  ```sh
  bazel build -c opt --action_env=BAZEL_CXXOPTS="-std=c++17" --subcommands=true ...
  ```

* on Windows when using MSVC:
  ```sh
  bazel build -c opt --cxxopt="/std:c++17" --subcommands=true ...
  ```

## Running Tests

To build this example you should use:

* on UNIX:
  ```sh
  bazel test -c opt --action_env=BAZEL_CXXOPTS="-std=c++17" --test_output=all ...
  ```

* on Windows when using MSVC:
  ```sh
  bazel test -c opt --cxxopt="/std:c++17" --test_output=all ...
  ```

## Tutorial
### Visibility

In Bazel, subdirectories containing BUILD files are known as packages.<br>
The new property `visibility` will tell Bazel which package(s) can reference this target, in this case the `//main` package can use `hello-time` library. 

lib/BUILD:
```bazel
cc_library(
    name = "hello-time",
    srcs = ["hello-time.cc"],
    hdrs = ["hello-time.h"],
    visibility = ["//main:__pkg__"],
)
```

### local dependencies

To use our `hello-time` libary, an extra dependency is added in the form of `//path/to/package:target_name`, in this case, it's `//lib:hello-time`.

main/BUILD:
```bazel
cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cc"],
    deps = [
        ":hello-greet",
        "//lib:hello-time",
    ],
)
```

## CI Setup

Please take a look at [.github/workflows](.github/workflows) to find the configuration file for each jobs.

To install *bazel* on each hosted runner, follow these links:
ref: https://docs.github.com/en/actions/using-github-hosted-runners/customizing-github-hosted-runners#installing-software-on-windows-runners

* Linux (Ubuntu latest LTS) -> `apt-get install bazel`<br>
  ref: https://docs.bazel.build/versions/main/install-ubuntu.html<br>
  (as of 06/2021 Ubuntu 20.04 LTS is still not supported according to the doc...)
* MacOS -> `brew install bazel`<br>
  ref: https://formulae.brew.sh/formula/bazel#default
* Windows -> `choco install bazel`<br>
  ref: https://community.chocolatey.org/packages/bazel/

## Appendices

Few links on the subject...

### Resources

Project layout:
* The Pitchfork Layout Revision 1 (cxx-pflR1)

Bazel:
* https://docs.bazel.build/versions

### Misc

Image has been generated using [plantuml](http://plantuml.com/):
```bash
plantuml -Tsvg docs/{file}.dot
```
So you can find the dot source files in [docs](docs).

## License

Apache 2. See the LICENSE file for details.

## Disclaimer

This is not an official Google product, it is just code that happens to be
owned by Google.

