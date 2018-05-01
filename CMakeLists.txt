cmake_minimum_required(VERSION 2.8)
project(task_planner)

# Build setup
set(CMAKE_BUILD_TYPE "Release")
add_definitions("-O2")
add_definitions("-DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255 -DDO_NOT_USE_SHARED_MEMORY")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

find_package(Eigen3 REQUIRED)
find_package(Pangolin REQUIRED)
find_package(cilantro REQUIRED)
find_package(OpenCV REQUIRED)

set(OTHER_INCLUDES ${EIGEN3_INCLUDE_DIRS} ${Pangolin_INCLUDE_DIRS} ${cilantro_INCLUDE_DIRS})
set(LINK_LIBRARIES ${Pangolin_LIBRARIES} ${cilantro_LIBRARIES})

include_directories(include)
include_directories(external/include)
include_directories(${OTHER_INCLUDES})

file(GLOB_RECURSE ext_src ${CMAKE_SOURCE_DIR}/external/*.c ${CMAKE_SOURCE_DIR}/external/*.cpp)

add_executable(task_planner ${ext_src} src/blah.cpp src/vrep_utils.cpp src/vrep_kinect.cpp)
target_link_libraries(${PROJECT_NAME} ${Pangolin_LIBRARIES} ${cilantro_LIBRARIES})
