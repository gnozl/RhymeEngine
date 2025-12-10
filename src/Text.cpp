//
// Created by Gerardo Gonzalez on 11/23/25.
//

#include <string>
#include <utility>
#include "../include/Text.h"

Text::Text() = default;

Text::~Text() = default;

int Text::getTotalWords() const {
    int totalWords = 0;
    for (Line line : lines) {
        for (Word word : line.getWords()) {
            totalWords++;
        }
    }
    return totalWords;
}

void Text::setRhymePattern(const std::string& rhymePattern) {
}

void Text::addLine(Line & line) {
    //std::cout << "Text::addLine()" << std::endl;
    this->lines.push_back(line);
}

void Text::print() const{
    //std::cout << "Text::print()" << std::endl;
    for (Line line : lines) {
        for (const Word& word : line.getWords()) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}

void Text::printIPA() const {
    //std::cout << "Text::printIPA()" << std::endl;
    for (Line line : lines) {
        for (const Word& word : line.getWords()) {
            if (word.getPronunciation() == "")
                {std::cout << "???" << " ";}
            else {
                std::cout << word.getPronunciation() << " ";
            }
        }
        std::cout << std::endl;
    }
}
