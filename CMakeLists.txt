cmake_minimum_required(VERSION 3.8)
project(json)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp JSONObject.h structure/Node.h structure/DNode.h structure/LinearList.h structure/SimpleLinearList.h
        structure/DoubleLinkedLinearList.h structure/Queue.h structure/Stack.h structure/LinearListOperator.h )
add_executable(jsonTest ${SOURCE_FILES})