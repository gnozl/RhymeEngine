cmake_minimum_required(VERSION 4.0)
project(RhymeEngine)

set(CMAKE_CXX_STANDARD 20)

#Enable Testing
enable_testing()

#Core Rhyme Engine Library
add_library(RhymeEngine
        include/Word.h
        include/phonemes.h
        include/colors.h
        src/Word.cpp
        include/PartsOfSpeech.h
        include/RhymeEngine.h
        src/RhymeEngine.cpp
        src/Text.cpp
        src/Line.cpp
)

#applies to EVERY exe
link_libraries(RhymeEngine)

# main
add_executable(rhyme_engine src/main.cpp src/main.cpp)

# Tests
add_executable(test_word_make tests/test_word.cpp)
add_executable(test_enums tests/test_enums.cpp)
#add_executable(test_dictionary tests/test_dictionary.cpp)

# Register tests with CTest
add_test(NAME EnumTest COMMAND test_enums)
add_test(NAME WordMakeTest COMMAND test_word_make)
#add_test(NAME DictionaryTest COMMAND test_dictionary)

