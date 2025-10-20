cmake_minimum_required(VERSION 4.0)
project(RhymeEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(RhymeEngine src/main.cpp
        include/Word.h
        include/Line.h
        include/Text.h
        include/RhymeEngine.h
        include/phonemes.h
)
