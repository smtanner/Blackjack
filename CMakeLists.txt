cmake_minimum_required(VERSION 3.29)
project(Blackjack)

set(CMAKE_CXX_STANDARD 20)

add_executable(Blackjack main.cpp
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Hand.cpp
        Hand.h
        Game.cpp
        Game.h)
