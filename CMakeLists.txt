cmake_minimum_required(VERSION 3.6)
project(hooks)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        hooks.cpp
        hooks.h config.cpp config.h context.cpp context.h factory.cpp factory.h)
add_executable(hooks ${SOURCE_FILES})