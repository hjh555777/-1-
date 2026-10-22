cmake_minimum_required(VERSION 3.10)
project(ArmorVision)
set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(hw2)

add_executable(vision_main main.cpp)
target_link_libraries(vision_main hw2_lib ${OpenCV_LIBS})
