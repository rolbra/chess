cmake_minimum_required(VERSION 3.15.6)
project(chess)

FILE(GLOB_RECURSE SRC_LOCAL src/*)  #if problem on first compile add single cpp files or folders as a parameter here
SET(SRCFILES ${SRC_LOCAL})

include_directories(src src/gui src/logic src/input src/control)

add_executable(chess WIN32 ${SRCFILES})

target_link_libraries(chess "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x86/gdiplus.lib")