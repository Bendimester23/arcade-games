cmake_minimum_required(VERSION 3.21)
project(breakout)

find_package(raylib CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(breakout main.cpp config.h Player.cpp Player.h Game.cpp Game.h Ball.cpp Ball.h Brick.cpp Brick.h)
#target_link_libraries(breakout PUBLIC raylib)
target_include_directories(breakout PRIVATE ${raylib_INCLUDE_DIRS})
target_link_libraries(breakout PRIVATE ${raylib_LIBRARIES})
IF (WIN32)
    target_link_libraries(breakout PRIVATE -lpthread)
ENDIF()
