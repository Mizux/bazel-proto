add_library(Bar)

get_cpp_proto(PROTO_HDRS PROTO_SRCS)
target_sources(Bar
  PRIVATE
    bar.h bar.cc
    ${PROTO_HDRS} ${PROTO_SRCS}
)
target_include_directories(Bar
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(Bar PUBLIC cxx_std_17)
set_target_properties(Bar PROPERTIES
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER "bar.h;${PROTO_HDRS}")
target_link_libraries(Bar PUBLIC protobuf::libprotobuf)
add_library(${PROJECT_NAMESPACE}::Bar ALIAS Bar)

# Test
if(NOT BUILD_TESTING)
  add_cpp_test(bar_test.cc)
endif()

# Install
include(GNUInstallDirs)
install(TARGETS Bar
  EXPORT ${PROJECT_NAME}Targets
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/bar
)
