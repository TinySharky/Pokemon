cmake_minimum_required(VERSION 3.29)
project(Pokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pokemon main.cpp
        Card.cpp
        pokemonCard.h
        pokemonCard.cpp
        EnergyCard.cpp
        TrainerCard.h
        TrainerCard.cpp
        Player.cpp)
