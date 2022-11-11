cmake_minimum_required(VERSION 3.15.6)
project(chess)

FILE(GLOB HEADERS_LOCAL src/*.hpp)
FILE(GLOB SRC_LOCAL src/*.cpp)

FILE(GLOB_RECURSE HEADERS_EXTERNAL src/gui/*.h src/logic/*.h src/input/*.h)
FILE(GLOB_RECURSE SRC_EXTERNAL src/gui/*.cpp src/logic/*.cpp src/input/*.cpp)

SET(HEADERS ${HEADERS_LOCAL} ${HEADERS_EXTERNAL})
SET(SRC ${SRC_LOCAL} ${SRC_EXTERNAL})

SET(SRCFILES 
	${SRC} 
	${HEADERS}
)

include_directories(src src/gui src/logic src/input)

add_executable(chess WIN32 ${SRCFILES})

target_link_libraries(chess "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x86/gdiplus.lib")