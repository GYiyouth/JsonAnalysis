cmake_minimum_required(VERSION 3.8)
project(json)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp JSONObject.cpp JSONObject.h)
add_executable(jsonTest ${SOURCE_FILES})