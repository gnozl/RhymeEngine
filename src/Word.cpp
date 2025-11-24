//
// Created by Gerardo Gonzalez on 11/16/25.
//

#include "../include/Word.h"


bool Word::isVowel(const PHONEME phone) {
    if (phone > 0 && phone < 20) return true;
    return false;
}

Word::Word() {
    this->english = "";
    this->partOfSpeech = NO_POS;
    this->pronunciation = "";
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

void Word::printPronunciation() const {
    std::cout << pronunciation;
}

void Word::printEnglish() const {
    std::cout << english << std::endl;
}

void Word::setEnglish(std::string english) {
    this->english = std::move(english);
}

void Word::setPartOfSpeech(POS partOfSpeech) {
    this->partOfSpeech = partOfSpeech;
}

void Word::setPartOfSpeech(char partOfSpeech) {
    if (!charToPOS.contains(partOfSpeech)) {
        return;
    }
    else {
        this->partOfSpeech = charToPOS.at(partOfSpeech);
    }
}

void Word::setPronunciation(std::string& pronunciation_string) {
    this->pronunciation = std::move(pronunciation_string);
    std::erase(this->pronunciation, '/');

    for (char c : this->pronunciation) {
        if (c == '/' || c == '\'' || c == ',' || c == '_') continue;
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