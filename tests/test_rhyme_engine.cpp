//
// Created by Gerardo Gonzalez on 12/1/25.
//


#include "../include/RhymeEngine.h"

int main() {
    //run tests without crashing
    RhymeEngine rhymeEngine;
    rhymeEngine.createDictionary();
    rhymeEngine.runRhymeEngine("test/test1");
    return 0;
}
