//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_WORD_H
#define RHYMEENGINE_WORD_H
#include <string>
#include "phonemes.h"

class Word {
private:

    int syllables;
    std::string english;
    std::string ipa_pronunciation;
    std::vector<phoneme> phonemes;

public:
    Word();
    ~Word();

    int getSyllables();
    std::string getEnglish();
    std::string getIPAPronunciation();
    phoneme getPhoneme(int index);

    void printPhonemes();
    void printEnglish();
    void printIPA();


};

#endif //RHYMEENGINE_WORD_H
