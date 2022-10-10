cmake_minimum_required(VERSION 3.15.6)
project(chess)

FILE(GLOB HEADERS_LOCAL src/*.hpp)
FILE(GLOB SRC_LOCAL src/*.cpp)

FILE(GLOB_RECURSE HEADERS_EXTERNAL src/board/*.h)
FILE(GLOB_RECURSE SRC_EXTERNAL src/board/*.cpp)

SET(HEADERS ${HEADERS_LOCAL} ${HEADERS_EXTERNAL})
SET(SRC ${SRC_LOCAL} ${SRC_EXTERNAL})

SET(SRCFILES 
	${SRC} 
	${HEADERS}
)
message( SRCFILES: ${SRCFILES})

include_directories(src src/board)

add_executable(chess WIN32 ${SRCFILES})