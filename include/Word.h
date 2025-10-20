//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_WORD_H
#define RHYMEENGINE_WORD_H
#include <string>
#include "phonemes.h"

enum COLOR {NONE}; //TODO: fill with colors for printing

class Word {
private:

    int syllables;
    std::string english;
    std::string ipa_pronunciation;
    std::vector<PHONEME> phonemes;
    COLOR color = NONE;

public:
    Word();
    ~Word();

    int getSyllables() {return syllables;};
    std::string getEnglish() {return english;};
    std::string getIPAPronunciation() {return ipa_pronunciation;};
    PHONEME getPhoneme(int index) {return phonemes[index];};
    COLOR getColor() const {return color;};

    void printPhonemes();
    void printEnglish();
    void printWithColor();
    void printIPA();

    void setSyllables(int syllables);
    void setColor(COLOR color);



};

#endif //RHYMEENGINE_WORD_H
