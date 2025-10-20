//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_LINE_H
#define RHYMEENGINE_LINE_H
#include "Word.h"
#include <vector>

class Line {
    private:
    int numberOfWords = 0;
    std::vector<Word*> words;
    int numberOfSyllables = 0;
    //Not sure if this is the best way to store rhythm
    std::vector<bool> rhythm;

    public:
    explicit Line(std::string line);
    ~Line();

    void addWord(Word* word);
    void setRhythm(bool stress);
    int getNumberOfWords();
    int getNumberOfSyllables();
    std::vector<Word*> getWords(int index);
    std::vector<bool> getRhythm(int index);
};

#endif //RHYMEENGINE_LINE_H