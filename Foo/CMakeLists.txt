add_library(Foo)

get_cpp_proto(PROTO_HDRS PROTO_SRCS)
target_sources(Foo
  PRIVATE
    include/foo/Foo.hpp
    src/Foo.cpp
    ${PROTO_HDRS} ${PROTO_SRCS}
)
target_include_directories(Foo
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(Foo PUBLIC cxx_std_17)
set_target_properties(Foo PROPERTIES
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER include/foo/Foo.hpp)
target_link_libraries(Foo PUBLIC protobuf::libprotobuf)
add_library(${PROJECT_NAMESPACE}::Foo ALIAS Foo)

add_subdirectory(tests)

# Install
install(TARGETS Foo
  EXPORT ${PROJECT_NAME}Targets
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/foo
)
