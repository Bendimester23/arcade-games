cmake_minimum_required(VERSION 3.21)
project(breakout)

find_package(raylib 3.0)

set(CMAKE_CXX_STANDARD 14)

add_executable(breakout main.cpp config.h Player.cpp Player.h Game.cpp Game.h Ball.cpp Ball.h Brick.cpp Brick.h)
target_link_libraries(breakout PUBLIC raylib)
