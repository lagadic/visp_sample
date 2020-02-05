project(visp-sample)

cmake_minimum_required(VERSION 2.6)

#--------------------------------------------------------------------
# By default set release configuration
#--------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None Debug Release" FORCE)
endif()

#--------------------------------------------------------------------
# Detect ViSP
#--------------------------------------------------------------------
find_package(VISP REQUIRED)


#--------------------------------------------------------------------
# Propagate in subdirs
#--------------------------------------------------------------------
add_subdirectory(ar)
add_subdirectory(blob)
add_subdirectory(core)
add_subdirectory(detection)
add_subdirectory(gui)
add_subdirectory(io)
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

#----------------------------------------------------------------------
# For Dart server and tests
# We use CDash set through CTestConfig.cmake file
# Dashboards are sent to http://cdash.irisa.fr/CDash/index.php?project=ViSP
#----------------------------------------------------------------------
enable_testing()
include(Dart)

