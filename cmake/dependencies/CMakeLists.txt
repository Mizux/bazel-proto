include(FetchContent)
set(FETCHCONTENT_QUIET OFF)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_TESTING OFF)
set(CMAKE_Fortran_COMPILER OFF)

# ##############################################################################
# ZLIB
# ##############################################################################
if(BUILD_ZLIB)
  message(CHECK_START "Fetching ZLIB")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  set(ZLIB_BUILD_EXAMPLES OFF)
  FetchContent_Declare(
    zlib
    GIT_REPOSITORY "https://github.com/madler/ZLIB.git"
    GIT_TAG "v1.3.1"
    PATCH_COMMAND git apply --ignore-whitespace "${CMAKE_CURRENT_LIST_DIR}/../../patches/ZLIB.patch")
  FetchContent_MakeAvailable(zlib)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

# ##############################################################################
# ABSEIL-CPP
# ##############################################################################
if(BUILD_absl)
  message(CHECK_START "Fetching Abseil-cpp")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  set(ABSL_ENABLE_INSTALL ON)
  set(ABSL_USE_SYSTEM_INCLUDES ON)
  set(ABSL_PROPAGATE_CXX_STD ON)
  set(ABSL_BUILD_TESTING OFF)
  FetchContent_Declare(
    absl
    GIT_REPOSITORY "https://github.com/abseil/abseil-cpp.git"
    GIT_TAG "20240116.2"
    GIT_SHALLOW TRUE
    PATCH_COMMAND git apply --ignore-whitespace "${CMAKE_CURRENT_LIST_DIR}/../../patches/abseil-cpp-20240116.2.patch"
  )
  FetchContent_MakeAvailable(absl)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

# ##############################################################################
# Protobuf
# ##############################################################################
if(BUILD_Protobuf)
  message(CHECK_START "Fetching Protobuf")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  set(protobuf_BUILD_TESTS OFF)
  set(protobuf_BUILD_SHARED_LIBS OFF)
  set(protobuf_BUILD_EXPORT OFF)
  set(protobuf_MSVC_STATIC_RUNTIME OFF)
  #set(protobuf_BUILD_LIBUPB ON)
  FetchContent_Declare(
    Protobuf
    GIT_REPOSITORY "https://github.com/protocolbuffers/protobuf.git"
    #GIT_TAG "v28.0-rc1"
    #PATCH_COMMAND git apply --ignore-whitespace "${CMAKE_CURRENT_LIST_DIR}/../../patches/protobuf-v28.patch"

    #GIT_TAG "v27.2" # runtime error
    #PATCH_COMMAND git apply --ignore-whitespace "${CMAKE_CURRENT_LIST_DIR}/../../patches/protobuf-v27.2.patch"

    #GIT_TAG "49c83ab799977592744f50df93957ddec1e12e70" # auto gen, runtime error
    #GIT_TAG "abc9bae7c19d9fff4b0be0ffd3a01f947d3b487a" # Move MetaData, compile fail
    GIT_TAG "58baeb4c3b664f8918d24cef5151083d9da9767c" # OK, last commit without runtime error
    #GIT_TAG "v26.1"
    PATCH_COMMAND git apply --ignore-whitespace "${CMAKE_CURRENT_LIST_DIR}/../../patches/protobuf-v26.1.patch"

    #GIT_SHALLOW TRUE # to disable when using SHA1
    GIT_SUBMODULES ""
  )
  FetchContent_MakeAvailable(Protobuf)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

# ##############################################################################
# RE2
# ##############################################################################
if(BUILD_re2)
  message(CHECK_START "Fetching re2")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  set(RE2_BUILD_TESTING OFF)
  FetchContent_Declare(
    re2
    GIT_REPOSITORY "https://github.com/google/re2.git"
    GIT_TAG "2024-04-01"
    GIT_SHALLOW TRUE
    #PATCH_COMMAND git apply --ignore-whitespace "${CMAKE_CURRENT_LIST_DIR}/../../patches/re2-2024-04-01.patch"
  )
  FetchContent_MakeAvailable(re2)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

###############
##  TESTING  ##
###############
if(BUILD_googletest)
  message(CHECK_START "Fetching googletest")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
    GIT_SHALLOW TRUE
  )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  set(INSTALL_GTEST OFF)
  set(GTEST_HAS_ABSL ON)
  FetchContent_MakeAvailable(googletest)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()
