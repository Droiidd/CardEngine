cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        Card.h
        Card.cpp
        Deck.cpp
        Deck.h
        BlackJack.cpp
        BlackJack.h)
