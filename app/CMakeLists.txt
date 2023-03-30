add_executable(App)
target_sources(App PRIVATE main.cc)
target_compile_features(App PRIVATE cxx_std_17)
set_target_properties(App PROPERTIES
  VERSION ${PROJECT_VERSION})
# note: macOS is APPLE and also UNIX !
if(APPLE)
  set_target_properties(App PROPERTIES
    INSTALL_RPATH "@loader_path/../${CMAKE_INSTALL_LIBDIR}")
elseif(UNIX AND NOT APPLE)
  set_target_properties(App PROPERTIES
    INSTALL_RPATH "$ORIGIN/../${CMAKE_INSTALL_LIBDIR}")
endif()
target_link_libraries(App PRIVATE
  absl::strings
  ${PROJECT_NAMESPACE}::FooBar
)
add_executable(${PROJECT_NAMESPACE}::App ALIAS App)

if(BUILD_TESTING)
  add_test(NAME app_test COMMAND App)
endif()

# Install
include(GNUInstallDirs)
install(TARGETS App
  EXPORT ${PROJECT_NAME}Targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
