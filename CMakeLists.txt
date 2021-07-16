cmake_minimum_required(VERSION 3.19)
project(simpleXGDbaseDir)

set(CMAKE_CXX_STANDARD 17)

add_library(sXDGbd SHARED src/sXDGbd.cpp)
target_include_directories(sXDGbd PUBLIC include)