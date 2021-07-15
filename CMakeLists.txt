cmake_minimum_required(VERSION 3.19)
project(simpleXGDbaseDir)

set(CMAKE_CXX_STANDARD 17)

add_library(${CMAKE_PROJECT_NAME} src/simpleXDBbaseDir.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)