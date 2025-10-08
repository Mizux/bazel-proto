add_library(Foo)
get_cpp_proto(PROTO_HDRS PROTO_SRCS)
target_sources(Foo
  PRIVATE
    foo.h foo.cc
    ${PROTO_HDRS} ${PROTO_SRCS})
target_include_directories(Foo
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>)
target_compile_features(Foo PUBLIC cxx_std_17)
if(MSVC AND BUILD_SHARED_LIBS)
  target_compile_definitions(Foo INTERFACE "PROTO_DLL=__declspec(dllimport)")
  target_compile_definitions(Foo PRIVATE "PROTO_DLL=__declspec(dllexport)")
 else()
  target_compile_definitions(Foo PUBLIC "PROTO_DLL=")
endif()
if(APPLE)
  set_target_properties(Foo PROPERTIES
    INSTALL_RPATH "@loader_path")
elseif(UNIX)
  set_target_properties(Foo PROPERTIES
    INSTALL_RPATH "$ORIGIN")
endif()
set_target_properties(Foo PROPERTIES
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER "foo.h;${PROTO_HDRS}")
target_link_libraries(Foo PUBLIC protobuf::libprotobuf)
add_library(${PROJECT_NAMESPACE}::Foo ALIAS Foo)

# Test
if(BUILD_TESTING)
  add_cpp_test(${CMAKE_CURRENT_SOURCE_DIR}/foo_test.cc)
endif()

# Install
install(TARGETS Foo
  EXPORT ${PROJECT_NAME}Targets
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/foo)
