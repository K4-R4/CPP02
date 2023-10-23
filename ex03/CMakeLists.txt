cmake_minimum_required(VERSION 3.26)
project(ex03)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

AUX_SOURCE_DIRECTORY(. SRCS)

add_executable(ex03 ${SRCS}
        Point.hpp)
