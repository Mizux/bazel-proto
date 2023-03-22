# Check dependencies
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREAD_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

# Tell find_package() to try “Config” mode before “Module” mode if no mode was specified.
# This should avoid find_package() to first find our FindXXX.cmake modules if
# distro package already provide a CMake config file...
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE)

#find_package(pybind11 REQUIRED)

