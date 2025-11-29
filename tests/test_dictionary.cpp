//
// Created by Gerardo Gonzalez on 11/25/25.
//
#include <cassert>
#include "../src/RhymeEngine.cpp"

int main() {
    RhymeEngine rhymeEngine;
    rhymeEngine.createDictionary("../addFilesHere/test_dict.txt");
    std::string test_word = "the";

    pair<char,string> test;
    test = rhymeEngine.getDictionaryEntry(test_word);
    assert(test.first == 'D');
    assert(test.second == "/D//^/");
    std::cout << test.first << " " << test.second << std::endl;

    Word word = rhymeEngine.createWord(test_word);
    assert(word.getEnglish() == "the");
    assert(word.getSyllables() == 1);
    assert(word.getPartOfSpeech() == DETERMINER);
    assert(word.getPronunciation() == "D^");

    return 0;
}