//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_WORD_H
#define RHYMEENGINE_WORD_H
#include "Phonemes.h"
#include "PartsOfSpeech.h"
#include "Colors.h"
#include <vector>
#include <iostream>
#include <string>

class Word {
private:

    std::string english;
    POS partOfSpeech;
    std::string pronunciation;

    int syllables = 0;
    std::vector<PHONEME> phonemes;
    COLOR color = NONE;


    static bool isVowel(PHONEME phone);

public:
    Word(std::string english, POS partOfSpeech, std::string pronunciation);
    ~Word();

    int getSyllables() const {return syllables;};
    std::string getEnglish() {return english;};
    std::string getPronunciation() {return pronunciation;};
    PHONEME getPhoneme(int index) const {return phonemes[index];};
    unsigned phonemeCount() const {return phonemes.size();};
    COLOR getColor() const {return color;};
    POS getPartOfSpeech() const {return partOfSpeech;};

    void printPronunciation() const;
    void printEnglish() const;

    void setColor(COLOR color);
    void addPhoneme(PHONEME phoneme);
    void printInColor() const;

    friend std::ostream& operator<<(std::ostream& os, const Word& word);
};

#endif //RHYMEENGINE_WORD_H
