//
// Created by Gerardo Gonzalez on 11/23/25.
//

#include <string>
#include <utility>
#include "../include/Text.h"

Text::Text() {
    title = "";
}

Text::Text(std::string title, std::string & fileName) {
    this->title = std::move(title);
}

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
    this->lines.push_back(line);
}

void Text::print() {
    for (Line line : lines) {
        for (Word word : line.getWords()) {
            std::cout << word << " ";
        }
    }
}
