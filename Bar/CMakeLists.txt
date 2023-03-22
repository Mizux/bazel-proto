# Generate Protobuf cpp sources
set(PROTO_HDRS)
set(PROTO_SRCS)
file(GLOB_RECURSE proto_files RELATIVE ${PROJECT_SOURCE_DIR} "*.proto")

## Get Protobuf include dir
get_target_property(protobuf_dirs protobuf::libprotobuf INTERFACE_INCLUDE_DIRECTORIES)
foreach(dir IN LISTS protobuf_dirs)
  if (NOT "${dir}" MATCHES "INSTALL_INTERFACE|-NOTFOUND")
    message(STATUS "Adding proto path: ${dir}")
    list(APPEND PROTO_DIRS "--proto_path=${dir}")
  endif()
endforeach()

foreach(PROTO_FILE IN LISTS proto_files)
  message(STATUS "protoc proto(cc): ${PROTO_FILE}")
  get_filename_component(PROTO_DIR ${PROTO_FILE} DIRECTORY)
  get_filename_component(PROTO_NAME ${PROTO_FILE} NAME_WE)
  set(PROTO_HDR ${PROJECT_BINARY_DIR}/${PROTO_DIR}/${PROTO_NAME}.pb.h)
  set(PROTO_SRC ${PROJECT_BINARY_DIR}/${PROTO_DIR}/${PROTO_NAME}.pb.cc)
  message(STATUS "protoc hdr: ${PROTO_HDR}")
  message(STATUS "protoc src: ${PROTO_SRC}")
  add_custom_command(
    OUTPUT ${PROTO_SRC} ${PROTO_HDR}
    COMMAND ${PROTOC_PRG}
    "--proto_path=${PROJECT_SOURCE_DIR}"
    ${PROTO_DIRS}
    "--cpp_out=${PROJECT_BINARY_DIR}"
    ${PROTO_FILE}
    DEPENDS ${PROTO_NAME}.proto ${PROTOC_PRG}
    COMMENT "Generate C++ protocol buffer for ${PROTO_FILE}"
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    VERBATIM)
  list(APPEND PROTO_HDRS ${PROTO_HDR})
  list(APPEND PROTO_SRCS ${PROTO_SRC})
endforeach()

add_library(Bar "")

target_sources(Bar
  PRIVATE
    include/bar/Bar.hpp
    src/Bar.cpp
    ${PROTO_HDRS} ${PROTO_SRCS}
  )
target_include_directories(Bar
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    #$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/Bar>
    $<INSTALL_INTERFACE:include>
  )
target_compile_features(Bar PUBLIC cxx_std_17)
set_target_properties(Bar PROPERTIES
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER include/bar/Bar.hpp)
target_link_libraries(Bar PUBLIC protobuf::libprotobuf)
add_library(${PROJECT_NAMESPACE}::Bar ALIAS Bar)

add_subdirectory(tests)

# Install
include(GNUInstallDirs)
install(TARGETS Bar
  EXPORT ${PROJECT_NAME}Targets
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/bar
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  #RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
