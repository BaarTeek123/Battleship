cmake_minimum_required(VERSION 3.21)
project(Battleship)

set(CMAKE_CXX_STANDARD 14)

add_executable(Battleship main.cpp Board.cpp Board.h GameManager.cpp GameManager.h Ship.cpp Ship.h)
