//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_LINE_H
#define RHYMEENGINE_LINE_H
#include "Word.h"
#include <vector>

class Line {
    private:
    std::vector<Word> words;
    //Not sure if this is the best way to store rhythm
    std::vector<bool> rhythm;

    public:
    Line();
    ~Line();

    void addWord(Word & word);
    void setRhythm();
    [[nodiscard]] int getNumberOfWords() const;
    [[nodiscard]] int getNumberOfSyllables() const;
    [[nodiscard]] std::vector<Word> & getWords(){return words;}
    [[nodiscard]] std::vector<bool> getRhythm();
};

#endif //RHYMEENGINE_LINE_H
