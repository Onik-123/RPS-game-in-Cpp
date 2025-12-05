cmake_minimum_required(VERSION 3.10)
project(RPS)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# compile AsciiRenderer.cpp as a separate library
add_library(AsciiRenderer AsciiRenderer.cpp)

set(SOURCES
    choice.cpp
    computer.cpp
    engine.cpp
    HumanPlayer.cpp
    main.cpp
)

add_executable(app ${SOURCES})

target_link_libraries(app AsciiRenderer)