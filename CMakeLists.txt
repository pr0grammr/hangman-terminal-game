cmake_minimum_required(VERSION 3.12)
project(hangman)

set(CMAKE_CXX_STANDARD 14)

add_executable(hangman main.cpp Hangman.cpp Hangman.h Player.h)