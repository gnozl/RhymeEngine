//
// Created by Gerardo Gonzalez on 11/23/25.
//

#include "../include/Line.h"
#include <sstream>

Line::Line() = default;
Line::~Line() = default;

void Line::addWord(Word & word) {
    this->words.push_back(word);
}

void Line::setRhythm() {
    //TODO: Set Rhythm
    }

int Line::getNumberOfWords() const {
    return this->words.size();
}

int Line::getNumberOfSyllables() const {
    int numberOfSyllables = 0;
    for (const Word & word : this->words) {
        numberOfSyllables += word.getSyllables();
    }
    return numberOfSyllables;
}

std::vector<bool> Line::getRhythm() {
    return this->rhythm;
}

