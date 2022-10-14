cmake_minimum_required(VERSION 3.15.6)
project(chess)

FILE(GLOB HEADERS_LOCAL src/*.hpp)
FILE(GLOB SRC_LOCAL src/*.cpp)

FILE(GLOB_RECURSE HEADERS_EXTERNAL src/board/*.h "C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/*.h")
FILE(GLOB_RECURSE SRC_EXTERNAL src/board/*.cpp)

SET(HEADERS ${HEADERS_LOCAL} ${HEADERS_EXTERNAL})
SET(SRC ${SRC_LOCAL} ${SRC_EXTERNAL})

SET(SRCFILES 
	${SRC} 
	${HEADERS}
)

include_directories(src src/board "C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um")

add_executable(chess WIN32 ${SRCFILES})

target_include_directories(chess PRIVATE "C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um")