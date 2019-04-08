cmake_minimum_required(VERSION 3.13)
project(gofish)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(gofish
        card.cpp
        card.h
        deck.cpp
        deck.h
        go_fish.cpp
        player.cpp
        player.h)
