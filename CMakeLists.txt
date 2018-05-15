cmake_minimum_required(VERSION 2.8)
project(vrep_cpp)

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

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/external/include)
include_directories(${OTHER_INCLUDES})
file(GLOB_RECURSE ext_src ${CMAKE_SOURCE_DIR}/external/*.c ${CMAKE_SOURCE_DIR}/external/*.cpp)

# Make library
add_library(${PROJECT_NAME} SHARED src/vrep_utils.cpp src/vrep_path.cpp src/vrep_kinect.cpp)
target_link_libraries(${PROJECT_NAME} ${Pangolin_LIBRARIES} ${cilantro_LIBRARIES})

# Examples
include_directories(${CMAKE_SOURCE_DIR}/examples/include)
file(GLOB_RECURSE examples_src ${CMAKE_SOURCE_DIR}/examples/*.c ${CMAKE_SOURCE_DIR}/examples/*.cpp)

add_executable(example_path ${ext_src} examples/example_path.cpp)
target_link_libraries(example_path ${Pangolin_LIBRARIES} ${cilantro_LIBRARIES} ${PROJECT_NAME})