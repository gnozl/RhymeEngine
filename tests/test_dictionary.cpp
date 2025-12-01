//
// Created by Gerardo Gonzalez on 11/25/25.
//
#include <cassert>
#include "../src/RhymeEngine.cpp"

void test_suffix() {
    // These words are not in the dictionary, so they must be found with
    // createWord() -> getDictionaryEntry() -> find_suffix()
    std::cout << "== WORDS WITH SUFFIX TEST ==" << std::endl;

    RhymeEngine engine;
    engine.createDictionary();

    std::string testWord = "jumping";

    pair<char, string> dictionaryEntry = engine.getDictionaryEntry(testWord);
    assert(dictionaryEntry.first == 'i');
    assert(dictionaryEntry.second == "J^mpiN");

    //{"ies", "ied",  "ing", "ed", "es","ly", "y", "s", "d"}
    testWord = "hurries";
    Word hurries = engine.createWord(testWord);
    assert(hurries.getEnglish() == "hurries");
    assert(hurries.getPartOfSpeech() == VERB);
    assert(hurries.getPronunciation() == "'h@riz");
    assert(hurries.getSyllables() == 2);
    std::cout << hurries << " " << hurries.getPronunciation() << std::endl;

    testWord = "swimming";
    Word swimming = engine.createWord(testWord);
    assert(swimming.getEnglish() == "swimming");
    assert(swimming.getPartOfSpeech() == NOUN);
    assert(swimming.getPronunciation() == "'swImiN");
    assert(swimming.getSyllables() == 2);
    std::cout << swimming << " " << swimming.getPronunciation() << std::endl;

    testWord = "burned";
    Word burned = engine.createWord(testWord);
    assert(burned.getEnglish() == "burned");
    assert(burned.getPartOfSpeech() == VERB);
    assert(burned.getPronunciation() == "b@rnd");
    assert(burned.getSyllables() == 1);
    std::cout << burned << " " << burned.getPronunciation() << std::endl;

    testWord = "slightly";
    Word slightly = engine.createWord(testWord);
    assert(slightly.getEnglish() == "slightly");
    assert(slightly.getPartOfSpeech() == ADVERB);
    assert(slightly.getPronunciation() == "sl1tli");
    assert(slightly.getSyllables() == 2);
    std::cout << slightly << " " << slightly.getPronunciation() << std::endl;

    std::cout << "✓ Find words with suffixes test passed\n";
}

void test_get_dictionary_entry() {
    std::cout << "== GET DICTIONARY ENTRY TEST ==" << std::endl;

    RhymeEngine rhymeEngine;
    rhymeEngine.createDictionary("../addFilesHere/test_dict.txt");
    std::string test_word = "the";

    pair<char,string> test = rhymeEngine.getDictionaryEntry(test_word);
    assert(test.first == 'D');
    assert(test.second == "D^");
    std::cout << test_word << " " << test.first << " " << test.second << std::endl;

    Word word = rhymeEngine.createWord(test_word);
    assert(word.getEnglish() == "the");
    assert(word.getSyllables() == 1);
    assert(word.getPartOfSpeech() == DETERMINER);
    assert(word.getPronunciation() == "D^");
    std::cout << word << " " << test.first << " " << test.second << std::endl;

    std::cout << "✓ Find word test passed\n";
}

int main() {
    std::cout << "== TESTING DICTIONARY FUNCTIONALITY ==" << std::endl;

    test_get_dictionary_entry();
    test_suffix();

    return 0;
}