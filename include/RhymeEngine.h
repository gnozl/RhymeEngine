//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_RHYMEENGINE_H
#define RHYMEENGINE_RHYMEENGINE_H
#include <string>

#include "Text.h"
using namespace std;

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
    vector<pair<string, COLOR>> rhymeColors;
    vector<int> syllableArray;
    vector<int> rhymeArray;
    unordered_map<string, pair<char, string>> rhymeDictionary;

public:

    RhymeEngine();
    ~RhymeEngine();

    // Turns dict.txt into an unordered map - sets up rhymeDictionary member variable
    void createDictionary(const string& dictionaryFilePath = "../src/dict.txt");

    void runRhymeEngine(std::string textFile = "default");

    // Asks user for file to open; Returns true if successful
    bool openTextFile(std::ifstream & file, const std::string & textFile);

    // Using selected filestream, create Text object, using dictionary; Returns text object
    Text createText(std::ifstream & inputFile);

    // Edits Word object using data from dictionary
    Word createWord(std::string &english);

    /* Finds exact match of word in dict.txt, inputs whole line into dictionaryEntry
     Returns {' ', " "} if no match found
     */
    [[nodiscard]] pair<char, string> getDictionaryEntry(const std::string &key);
    // If basic getDictionaryEntry search fails, run this
    [[nodiscard]] pair<char, string> checkForSuffixes(const std::string & key);

    // //TODO: Implement these next
    // static std::vector<std::string> findRhymes(Word & word);
    // static bool isRhyme(Word & word1, Word & word2);


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