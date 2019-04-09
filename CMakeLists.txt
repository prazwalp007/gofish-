cmake_minimum_required(VERSION 3.13)
project(gofish_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(gofish_
        card.cpp
        card.h
        CMakeLists.txt
        deck.cpp
        deck.h
        go_fish.cpp
        player.cpp
        player.h)
