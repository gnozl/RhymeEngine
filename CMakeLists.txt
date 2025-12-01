cmake_minimum_required(VERSION 4.0)
project(RhymeEngine)

set(CMAKE_CXX_STANDARD 20)

#Enable Testing
enable_testing()

#Core Rhyme Engine Library
add_library(RhymeEngine
        src/RhymeEngine.cpp
        src/Word.cpp
        src/Text.cpp
        src/Line.cpp
)

target_include_directories(RhymeEngine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# main
add_executable(rhyme_engine src/main.cpp)
target_link_libraries(rhyme_engine PRIVATE RhymeEngine)

# Tests
add_executable(test_word_make tests/test_word.cpp)
target_link_libraries(test_word_make PRIVATE RhymeEngine)
add_executable(test_enums tests/test_enums.cpp)
target_link_libraries(test_enums PRIVATE RhymeEngine)
add_executable(test_dictionary tests/test_dictionary.cpp)
target_link_libraries(test_dictionary PRIVATE RhymeEngine)

# Register tests with CTest
add_test(NAME EnumTest COMMAND test_enums)
add_test(NAME WordMakeTest COMMAND test_word_make)
add_test(NAME DictionaryTest COMMAND test_dictionary)

add_executable(test_rhyme_engine tests/test_rhyme_engine.cpp)
