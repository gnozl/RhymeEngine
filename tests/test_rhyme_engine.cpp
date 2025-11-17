//
// Created by Gerardo Gonzalez on 11/16/25.
//

#include <iostream>
#include "../include/Word.h"
#include <cassert>

void test_make_word() {
    Word word("examination", NOUN, "/I/g,z/&/m/^/'n/2//S//^/n");

    assert(word.getColor() == NONE);
    word.setColor(RED);

    std::cout << "The word " << word.getEnglish();
    std::cout << " is pronounced " << word.getPronunciation() << std::endl;
    std::cout << word.getEnglish() << " has " << word.getSyllables() << " syllables and " << word.phonemeCount() << " phonemes." << std::endl;

    assert(word.getSyllables() == 5);
    assert(word.phonemeCount() == 11);
    assert(word.getColor() == RED);

    word.addPhoneme(ZZ);

    assert(word.getSyllables() == 5);
    assert(word.phonemeCount() == 12);

    std::cout << "== COLOR PRINT TEST ==" << std::endl;
    word.printInColor();
    std::cout << std::endl;

    std::cout << "✓ Make Word test passed\n";
}

int main() {
    std::cout << "Running tests..." << std::endl;

    test_make_word();

    return 0;

}
