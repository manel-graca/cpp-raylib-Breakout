cmake_minimum_required(VERSION 3.31.6)
project(cpp-rlib-breakout VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib CONFIG REQUIRED)
add_executable(cpp-rlib-breakout 
    src/main.cpp 
    src/paddle.cpp
    src/ball.cpp
    src/game.cpp
)

target_link_libraries(cpp-rlib-breakout PRIVATE raylib)