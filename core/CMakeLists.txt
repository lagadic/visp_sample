project(sample-core)

cmake_minimum_required(VERSION 2.6)

# C++11 is needed for brace-enclosed initializer list in sample-vpVelocityTwistMatrix-3.cpp:9:37
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB src_cpp RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")

foreach(src ${src_cpp})
  # Compute the name of the binary to create
  get_filename_component(binary ${src} NAME_WE)

  # From source compile the binary and add link rules
  add_executable(${binary} ${src})
  # It is not requested to add explicitely ViSP libraries
  if(VISP_FOUND)
    include_directories(${VISP_INCLUDE_DIRS})
    target_link_libraries(${binary} ${VISP_LIBRARIES})
  endif()

  # Add test
  add_test(${binary} ${binary})
endforeach()
