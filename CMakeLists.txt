cmake_minimum_required(VERSION 4.0)
project(RhymeEngine)

set(CMAKE_CXX_STANDARD 20)

#Enable Testing
enable_testing()

#Add Rhyme Engine Library
add_library(RhymeEngine
        include/Word.h
        include/phonemes.h
        include/colors.h
        src/Word.cpp
        include/PartsOfSpeech.h
)

# Add test executable
add_executable(test_rhyme_engine tests/test_rhyme_engine.cpp)
target_link_libraries(test_rhyme_engine RhymeEngine)

# Register tests with CTest
add_test(NAME RhymeEngineTests COMMAND test_rhyme_engine)