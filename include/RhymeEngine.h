//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_RHYMEENGINE_H
#define RHYMEENGINE_RHYMEENGINE_H
#include <string>

#include "Text.h"

/* Rhyme Engine
 * This handles the text submitted by the user
 * Converts english text to IPA using IPA dictionary file
 * Stores both english and IPA as a Text
 * Does operations on created Text
 * Finds rhymes using dictionary file

*/

class RhymeEngine {
private:
    // sequences of phonemes to check rhymes against, and their associated color
    std::vector<std::tuple<std::string, COLOR>> rhymeColors;

    std::vector<int> syllableArray;
    std::vector<int> rhymeArray;

    // Opens dict.txt in filestream
    static void loadDictionary(std::ifstream & file);
    // Asks user for file to open; Returns true is successful
    static bool openFile(std::ifstream & file);

public:
    RhymeEngine();
    ~RhymeEngine();

    static void run();

    // Using selected filestream, create Text object, using dictionary; Returns true if successful
    static bool createText(std::ifstream &file, Text &text, std::ifstream &dictionary);

    // Edits Word object using data from dictionary
    static bool createWord(std::string &english, Word &word, std::ifstream &dictionary);

    /* Finds exact match of word in dict.txt, inputs whole line into dictionaryEntry
     Returns false if no match found
     */
    static bool findWordInDictionary(const std::string & english, std::ifstream & dictionary, std::string & dictionaryEntry);

    static std::vector<std::string> findRhymes(Word & word);
    static bool isRhyme(Word & word1, Word & word2);


    // TODO: Future Features
    // bool saveTextFile(const std::string& newFileName);
    //
    // void matchRhymeToColors(Word * word);
    // void printColorText();
    //
    // void setRhythm();
    //
    // void createSyllableArray();
    // void createRhymeArray();
    // std::string checkForPattern(std::vector<int>);
    //
    // int gradeText();
    // void printScore();

};

#endif //RHYMEENGINE_RHYMEENGINE_H