# Create a virtual environment with all tools installed
# ref: https://quay.io/repository/centos/centos
FROM quay.io/centos/centos:stream AS env
# Install system build dependencies
ENV PATH=/usr/local/bin:$PATH
RUN dnf -y update \
&& dnf -y install git wget zlib-devel \
&& dnf -y groupinstall "Development Tools" \
&& dnf clean all \
&& rm -rf /var/cache/dnf
# Install bazel
# see: https://docs.bazel.build/versions/master/install-redhat.html#installing-on-centos-7
RUN dnf config-manager --add-repo \
https://copr.fedorainfracloud.org/coprs/vbatts/bazel/repo/epel-8/vbatts-bazel-epel-8.repo \
&& dnf -y install bazel5 \
&& dnf clean all \
&& rm -rf /var/cache/dnf

FROM env AS devel
WORKDIR /home/project
COPY . .

FROM devel AS build
RUN bazel version
RUN bazel build \
 -c opt \
 --action_env=BAZEL_CXXOPTS="-std=c++17" \
 --subcommands=true \
 ...

FROM build AS test
RUN bazel test \
 -c opt \
 --action_env=BAZEL_CXXOPTS="-std=c++17" \
 --test_output=all \
 ...
