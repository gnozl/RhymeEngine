//
// Created by Gerardo Gonzalez on 12/2/25.
//


#include "../include/RhymeEngine.h"
#include <cassert>
#include <iostream>

int main() {
    std::cout << "==RHYME STRENGTH TEST==" << std::endl;
    RhymeEngine rhymeEngine;
    rhymeEngine.createDictionary();
    string wordstring = "care";
    Word care = rhymeEngine.createWord(wordstring);
    wordstring = "bear";
    Word bear = rhymeEngine.createWord(wordstring);
    wordstring = "wolves";
    Word wolves = rhymeEngine.createWord(wordstring);
    wordstring = "calling";
    Word calling = rhymeEngine.createWord(wordstring);
    wordstring = "falling";
    Word falling = rhymeEngine.createWord(wordstring);

    try {
        cout << "Care & Bear have rhyme strength " << rhymeEngine.rhymeStrength(care, bear) << endl;
        assert (rhymeEngine.rhymeStrength(care, bear) > 1);
        cout << "Care & Wolves have rhyme strength " << rhymeEngine.rhymeStrength(care, wolves) << endl;
        assert (rhymeEngine.rhymeStrength(care, wolves) == 0);
        cout << "Calling and Falling have rhyme strength " << rhymeEngine.rhymeStrength(calling, falling) << endl;
        assert (rhymeEngine.rhymeStrength(calling, falling) == 6); // vowels are +2, consonants are +1
    }
    catch (std::exception &e) {
        std::cerr << "\n❌ Test failed with exception: " << e.what() << "\n";
        return 1;
    };

    return 0;
}
