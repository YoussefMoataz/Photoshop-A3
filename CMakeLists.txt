cmake_minimum_required(VERSION 3.21)
project(Photoshop_A3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Photoshop_A3 GreyscaleImages.cpp)
add_executable(Photoshop_A3_Colored ColoredImages.cpp)
add_executable(Photoshop_A3_Demo demo2.cpp)
