//
// Created by Gerardo Gonzalez on 11/16/25.
//

#include "../include/Word.h"

#include <sstream>
#include <algorithm>
#include <utility>


bool Word::isVowel(const PHONEME phone) {
    if (phone > 0 && phone < BB) return true;
    return false;
}

Word::Word(std::string english, char POS, std::string pronunciation) {
    this->english = std::move(english);
    if (!charToPOS.contains(POS)) {
        throw std::invalid_argument("PartOfSpeech does not exist");
    }
    else {
        this->partOfSpeech = charToPOS.at(POS);
    }
    this->pronunciation = std::move(pronunciation);
    std::erase(this->pronunciation, '/');

    for (char c : this->pronunciation) {
        if (c == '/' || c == '\'' || c == ',' || c == '_') continue;
        addPhoneme(charToPhone.at(c));
    }
}

Word::Word(std::string english, POS partOfSpeech, std::string pronunciation) {
    this->english = std::move(english);
    this->partOfSpeech = partOfSpeech;
    this->pronunciation = std::move(pronunciation);
    std::erase(this->pronunciation, '/');


    for (char c : this->pronunciation) {
        if (c == '/' || c == '\'' || c == ',' || c == '_') continue;
        addPhoneme(charToPhone.at(c));
        }
    }

Word::~Word() = default;

int Word::getSyllables() const {
    int syllables = 0;
    for (const PHONEME phone : this->phonemes) {
        if (isVowel(phone)) {
            syllables++;
        }
    }
    return syllables;
}

void Word::setEnglish(std::string inputenglish) {
    std::cout << "setEnglish: " << inputenglish << std::endl;
    this->english = std::move(inputenglish);
}

void Word::setPartOfSpeech(POS inputpartOfSpeech) {
    this->partOfSpeech = inputpartOfSpeech;
}

void Word::setPartOfSpeech(char partOfSpeech) {
    std::cout << "setPartOfSpeech: " << partOfSpeech << std::endl;
    if (!charToPOS.contains(partOfSpeech)) {
        throw std::invalid_argument("PartOfSpeech does not exist");
    }
    else {
        this->partOfSpeech = charToPOS.at(partOfSpeech);
    }
}

void Word::setPronunciation(std::string pronunciation_string) {
    std::cout << "setPronunciation: " << pronunciation_string << std::endl;
    this->pronunciation = std::move(pronunciation_string);
    std::erase(this->pronunciation, '/');
    std::erase(this->pronunciation, ' ');
    std::erase(this->pronunciation, '\n');

    std::cout << this->pronunciation.length() << std::endl;
    std::cout << "||" << this->pronunciation << "||" << std::endl;

    for (char c : this->pronunciation) {
        if (c == '/' || c == '\'' || c == ',' || c == '_') continue;
        std::cout << "converting: " << c << std::endl;
        addPhoneme(charToPhone.at(c));
    }
}

void Word::setColor(COLOR color) {
    this->color = color;
}

void Word::addPhoneme(PHONEME phoneme) {
    phonemes.push_back(phoneme);
}

void Word::printInColor() const {
    if (color == -1) {
        std::cout << english;
    }
    else {
        std::cout <<"\033["<<color<<"m"<<english<<"\033[0m";
    }
}
std::ostream& operator<<(std::ostream& os, const Word& word) {
    if (word.color == -1) {os << word.english;}
    else {os << "\033[" << std::to_string(word.color) << "m" << word.english << "\033[0m";}
    return os;
}