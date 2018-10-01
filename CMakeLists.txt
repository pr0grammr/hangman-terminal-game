cmake_minimum_required(VERSION 3.12)
project(hangman_terminal_game)

set(CMAKE_CXX_STANDARD 14)
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")

set(CPACK_SOURCE_GENERATOR "TBZ2")

set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

set(CPACK_SOURCE_IGNORE_FILES "/build/;/.bzr/;~$;${CPACK_SOURCE_IGNORE_FILES}")

include(CPACK)

add_custom_target(dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)


add_executable(hangman main.cpp Game.cpp Game.h Colors.h)

install(TARGETS hangman DESTINATION /usr/local/bin)