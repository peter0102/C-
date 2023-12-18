cmake_minimum_required(VERSION 3.27)
project(TP4_pokemon)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(headers)
include_directories(source)

add_executable(TP4_pokemon
        headers/card.h
        headers/energy_card.h
        headers/player.h
        headers/pokemon_card.h
        headers/trainer_card.h
        source/energy_card.cpp
        source/player.cpp
        source/pokemon_card.cpp
        source/trainer_card.cpp
        main.cpp)
