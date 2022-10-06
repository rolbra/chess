cmake_minimum_required(VERSION 3.15.6)
project(chess)

set(SOURCES
    src/main.cpp
    src/board/field.cpp
    src/board/field.hpp
)

include_directories(src)

message( SOURCES: ${SOURCES})
add_executable(chess ${SOURCES})