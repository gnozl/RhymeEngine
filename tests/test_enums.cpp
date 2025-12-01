//
// Created by Gerardo Gonzalez on 11/25/25.
//

#include <iostream>
#include <ostream>
#include <cassert>

#include "../include/Phonemes.h"
#include "../include/PartsOfSpeech.h"

void test_Phonemes() {
    std::cout << "== Testing Phonemes.h ==" << std::endl;
    std::vector<PHONEME> phonemes = {};

    phonemes.reserve(NULL_PHONEME); // pre-allocate size of vector
    for (int i = 0; i < NULL_PHONEME; i++) {
        phonemes.push_back(static_cast<PHONEME>(i));
    }
    assert(phonemes.size() == NULL_PHONEME);

    // Verify NULL_PHONEME does not appear in vector
    assert(std::find(phonemes.begin(), phonemes.end(), NULL_PHONEME) == phonemes.end());

    for(auto charPhonePair : charToPhone){
        // Verify each phoneme exists in the charToPhone map
        assert(std::find (phonemes.begin(), phonemes.end(),charPhonePair.second ) != phonemes.end());
    }


    std::cout << "✓ Phoneme Enum test passed\n";
}

void test_partsOfSpeech() {
    std::cout << "== Testing PartsOfSpeech.h ==" << std::endl;

    std::vector<POS> partsOfSpeech = {};

    partsOfSpeech.reserve(NO_POS); // allocates memory , NO_POS is the final enum
    for (int i = 0; i < NO_POS; i++) {
        partsOfSpeech.push_back(static_cast<POS>(i));
    }

    assert(partsOfSpeech.size() == NO_POS);

    // Verify NO_POS does not appear in vector
    assert(std::find (partsOfSpeech.begin(), partsOfSpeech.end(), NO_POS) == partsOfSpeech.end());

    for(auto charPOSPair : charToPOS){
        // Verify each phoneme exists in the charToPOS map
        assert(std::find (partsOfSpeech.begin(), partsOfSpeech.end(), charPOSPair.second ) != partsOfSpeech.end());
    }

    std::cout << "✓ PartOfSpeech Enum test passed\n";
}

int main() {
    std::cout << "== ENUM COMPLETENESS TEST ==" << std::endl;
    test_Phonemes();
    test_partsOfSpeech();

    return 0;
}