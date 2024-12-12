cmake_minimum_required(VERSION 3.10)

project(visp-sample)

#--------------------------------------------------------------------
# By default set release configuration
#--------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None Debug Release" FORCE)
endif()

option(BUILD_TESTS  "Build tests" ON)

#--------------------------------------------------------------------
# Detect ViSP
#--------------------------------------------------------------------
find_package(VISP REQUIRED)

#----------------------------------------------------------------------
# Enable testing
#----------------------------------------------------------------------
if(BUILD_TESTS)
  enable_testing()
  mark_as_advanced(DART_ROOT)
  mark_as_advanced(BUILD_TESTING)
  include(CTest)
endif()

#--------------------------------------------------------------------
# Propagate in subdirs
#--------------------------------------------------------------------
add_subdirectory(ar)
add_subdirectory(blob)
add_subdirectory(core)
add_subdirectory(detection)
add_subdirectory(gui)
add_subdirectory(io)
add_subdirectory(json)
add_subdirectory(klt)
add_subdirectory(mbt)
add_subdirectory(me)
add_subdirectory(robot)
add_subdirectory(sensor)
add_subdirectory(tt)
add_subdirectory(video)
add_subdirectory(vision)
add_subdirectory(visual_features)
add_subdirectory(vs)
