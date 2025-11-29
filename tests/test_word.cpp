//
// Created by Gerardo Gonzalez on 11/16/25.
//

#include <iostream>
#include "../include/Word.h"
#include <cassert>

Word test_make_word() {
    std::cout << "== TEST MAKE WORD ==\n";
    Word word("examination", NOUN, "/I/g,z/&/m/^/'n/2//S//^/n");

    assert(word.getEnglish() == "examination");
    assert(word.getPartOfSpeech() == NOUN);
    assert(word.getPronunciation() == "Ig,z&m^'n2S^n");
    assert(word.getColor() == NONE);

    assert(word.getPhonemes().size() == 11);
    std::vector correctPronunciation = {IH, GG, ZZ, AH, MM, UH, NN, EI, SH, UH, NN};
    assert(word.getPhonemes() == correctPronunciation);

    std::cout << "✓ Make Word test passed\n";

    return word;
}

void test_cout_operator_overload(Word &word) {
    std::cout << "== TEST OPERATOR OVERLOAD ==\n";

    std::cout << "This word is not in color: "<< word << std::endl;
    word.setColor(BLUE_BRIGHT);
    std::cout << "This word is now bright blue: " << word << std::endl;

    std::cout << "✓ Operator << Overload test passed\n";
}

void test_getSyllables(const Word &word) {
    std::cout << "== TEST GET SYLLABLES ==\n";

    assert(word.getSyllables() == 5);

    Word test("test", VERB, "t/E/st");

    std::cout << "test has 1 syllable\n";
    assert(test.getSyllables() == 1);

    Word testing("testing", VERB, "t/E/stiN");

    std::cout << "testing has 2 syllables\n";
    assert(testing.getSyllables() == 2);

    std::cout << "✓ getSyllables() test passed\n";
}

void test_addPhonemes(Word &word) {
    std::cout << "== TEST ADD PHONEMES ==\n";

    assert(word.getPhonemes().size() == 11);
    word.addPhoneme(ZZ);
    assert(word.getPhonemes().size() == 12);

    std::cout << "✓ addPhonemes() test passed\n";
}


int main() {
    std::cout << "== TESTING WORD.CPP ==\n";

    Word word = test_make_word();
    test_cout_operator_overload(word);
    test_getSyllables(word);
    test_addPhonemes(word);

    return 0;
}
