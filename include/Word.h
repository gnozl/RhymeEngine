//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_WORD_H
#define RHYMEENGINE_WORD_H
#include <string>
#include "phonemes.h"

enum COLOR {NO_COLOR}; //TODO: fill with colors for printing
enum POS {NO_POS}; //TODO: fill with parts of speech
//TODO:Move enums to their own files

class Word {
private:

    int syllables;
    std::string english;
    std::string ipa_pronunciation;
    std::vector<PHONEME> phonemes;
    COLOR color = NO_COLOR;
    POS partOfSpeech = NO_POS;

public:
    Word(std::string english, std::string ipa_pronunciation);
    ~Word();

    int getSyllables() const {return syllables;};
    std::string getEnglish() {return english;};
    std::string getIPAPronunciation() {return ipa_pronunciation;};
    PHONEME getPhoneme(int index) const {return phonemes[index];};
    COLOR getColor() const {return color;};
    POS getPartOfSpeech() const {return partOfSpeech;};

    void printPhonemes();
    void printEnglish();
    void printWithColor(); //TODO: std::cout override

    void setSyllables(int syllables);
    void setColor(COLOR color);
    void addPhoneme(PHONEME phoneme); //TODO +=operator override
    void setPartOfSpeech(POS partOfSpeech);



};

#endif //RHYMEENGINE_WORD_H
