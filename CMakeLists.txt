cmake_minimum_required(VERSION 3.12)
project(hangman_terminal_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(hangman main.cpp Game.cpp Game.h Colors.h)

install(TARGETS hangman DESTINATION /usr/local/bin)