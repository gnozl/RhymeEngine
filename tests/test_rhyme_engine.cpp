//
// Created by Gerardo Gonzalez on 12/1/25.
//


#include <iostream>

#include "../include/RhymeEngine.h"

int main() {
    //run tests without crashing
    std::cout << "==TEST MAKE TEXT FROM FILES==" << std::endl;
    try{
    RhymeEngine rhymeEngine;
    rhymeEngine.createDictionary();
    std::cout << "Testing basic file ..." << std::endl;
    rhymeEngine.runRhymeEngine("../tests/test/test1");
    std::cout << "✓ Basic file test passed\n\n";
    std::cout << "Testing empty file..." << std::endl;
    rhymeEngine.runRhymeEngine("../tests/test/test2");
    std::cout << "✓ Empty file test passed\n\n";
    std::cout << "Testing nonsense file..." << std::endl;
    rhymeEngine.runRhymeEngine("../tests/test/test3");
    std::cout << "✓ Nonsense file input passed\n\n";
    std::cout << "Testing complicated file ..." << std::endl;
    rhymeEngine.runRhymeEngine("../tests/test/test4");
    std::cout << "✓ Complicated file input passed\n";

    }
    catch (const std::exception& e) {
        std::cerr << "\n❌ Test failed with exception: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
