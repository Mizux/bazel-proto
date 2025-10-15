get_cpp_proto(PROTO_HDRS PROTO_SRCS)
add_cxx_library(
  NAME
    Foo
  HEADERS
    foo.h ${PROTO_HDRS}
  SOURCES
    foo.cc ${PROTO_SRCS}
  LINK_LIBRARIES
    protobuf::libprotobuf
  INSTALL_DIR
    foo
)

add_cxx_test(
  NAME foo_test
  SOURCES foo_test.cc
  LINK_LIBRARIES ${PROJECT_NAMESPACE}::Foo
)
