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

    std::vector<PHONEME> phonemes;
    COLOR color = NONE;


    static bool isVowel(PHONEME phone);

public:
    Word();
    Word(std::string english, POS partOfSpeech, std::string pronunciation);
    ~Word();

    [[nodiscard]] int getSyllables() const;
    [[nodiscard]] std::string getEnglish() {return english;};
    [[nodiscard]] std::string getPronunciation() {return pronunciation;};
    [[nodiscard]] std::vector<PHONEME> getPhonemes() const {return phonemes;};
    [[nodiscard]] int phonemeCount() const {return phonemes.size();};
    [[nodiscard]] COLOR getColor() const {return color;};
    [[nodiscard]] POS getPartOfSpeech() const {return partOfSpeech;};

    void printPronunciation() const;
    void printEnglish() const;

    void setEnglish(std::string english);
    void setPartOfSpeech(POS partOfSpeech);
    void setPartOfSpeech(char partOfSpeech);

    void setPronunciation(std::string& pronunciation);

    void setColor(COLOR color);
    void addPhoneme(PHONEME phoneme);
    void printInColor() const;

    friend std::ostream& operator<<(std::ostream& os, const Word& word);
};

#endif //RHYMEENGINE_WORD_H
