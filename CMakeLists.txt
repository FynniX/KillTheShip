cmake_minimum_required(VERSION 3.17)
project(KillTheShip)

set(CMAKE_CXX_STANDARD 20)

add_executable(KillTheShip main.cpp Ship/Ship.cpp Ship/Ship.h Game/Game.cpp Game/Game.h)