//
// Created by Gerardo Gonzalez on 11/16/25.
//

#include <iostream>
#include "../include/Word.h"

int main() {
    Word word("examination", NOUN, "/I/g,z/&/m/^/'n/2//S//^/n");

    word.setColor(RED);

    std::cout << "The word " << word.getEnglish();
    std::cout << " is pronounced " << word.getPronunciation() << std::endl;
    std::cout << word.getEnglish() << " has " << word.getSyllables() << " syllables and " << word.phonemeCount() << " phonemes." << std::endl;

    std::cout << "== COLOR PRINT TEST ==" << std::endl;
    word.printInColor();
    std::cout << std::endl;
    return 0;
}
