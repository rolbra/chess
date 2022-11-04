cmake_minimum_required(VERSION 3.15.6)
project(chess)

FILE(GLOB HEADERS_LOCAL src/*.hpp)
FILE(GLOB SRC_LOCAL src/*.cpp)

FILE(GLOB_RECURSE HEADERS_EXTERNAL src/board/*.h src/referee/*.h src/figures/*h)
FILE(GLOB_RECURSE SRC_EXTERNAL src/board/*.cpp src/referee/*.cpp src/figures/*cpp)

SET(HEADERS ${HEADERS_LOCAL} ${HEADERS_EXTERNAL})
SET(SRC ${SRC_LOCAL} ${SRC_EXTERNAL})

SET(SRCFILES 
	${SRC} 
	${HEADERS}
)

include_directories(src src/board src/referee src/figures)

add_executable(chess WIN32 ${SRCFILES})

target_link_libraries(chess "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x86/gdiplus.lib")