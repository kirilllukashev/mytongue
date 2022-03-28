cmake_minimum_required(VERSION 3.21)
project(mytongue)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_HEADERS
        lexer.h
        syntax.h
        )
set(PROJECT_SOURCES

        compiler.cpp
        lexer.cpp
        syntax.cpp

        )
add_executable(test ${PROJECT_SOURCES} ${PROJECT_HEADERS})