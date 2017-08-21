cmake_minimum_required(VERSION 3.8)
project(json)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp JSONObject.cpp JSONObject.h Node.h DNode.h LinearList.h SimpleLinearList.h
        DoubleLinkedLinearList.h Queue.h Stack.h LinearListOperator.h)
add_executable(jsonTest ${SOURCE_FILES})