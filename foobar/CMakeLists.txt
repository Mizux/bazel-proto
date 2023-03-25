add_library(FooBar "")
target_sources(FooBar PRIVATE foobar.h foobar.cc)
target_include_directories(FooBar
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)
target_compile_features(FooBar PUBLIC cxx_std_17)
set_target_properties(FooBar PROPERTIES
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER foobar.h)
# note: macOS is APPLE and also UNIX !
if(APPLE)
  set_target_properties(FooBar PROPERTIES
    INSTALL_RPATH "@loader_path")
elseif(UNIX)
  set_target_properties(FooBar PROPERTIES
    INSTALL_RPATH "$ORIGIN")
endif()
target_link_libraries(FooBar
  PUBLIC
  ${PROJECT_NAMESPACE}::Foo
  ${PROJECT_NAMESPACE}::Bar
  )
add_library(${PROJECT_NAMESPACE}::FooBar ALIAS FooBar)

# Test
if(NOT BUILD_TESTING)
  add_cpp_test(foobar_test.cc)
endif()

# Install
include(GNUInstallDirs)
install(TARGETS FooBar
  EXPORT ${PROJECT_NAME}Targets
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/foobar
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  #RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
