if(NOT BUILD_EXAMPLES)
  return()
endif()

file(GLOB CPP_SRCS "*.cc")
foreach(FILE_NAME IN LISTS CPP_SRCS)
  add_cpp_example(${FILE_NAME})
endforeach()

