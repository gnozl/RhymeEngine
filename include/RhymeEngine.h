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
    static unordered_map<string, pair<string, string>> rhymeDictionary;

    // Turns dict.txt into an unordered map - sets up rhymeDictionary member variable
    static unordered_map<string, pair<string, string>> createDictionary(const string & dictionaryFilePath);


public:

    explicit RhymeEngine(const string& dictionaryFilePath = "../addFilesHere/dict.txt");
    ~RhymeEngine();

    static void run();

    // Asks user for file to open; Returns true if successful
    static bool openFile(std::ifstream & file);

    // Using selected filestream, create Text object, using dictionary; Returns true if successful
    static Text createText(std::ifstream & inputFile);

    // Edits Word object using data from dictionary
    static Word createWord(std::string &english);

    [[nodiscard]] static pair<string, string> checkForSuffixes(const std::string & key);

    [[nodiscard]] static pair<string, string> getDictionaryEntry(const std::string &key);

    /* Finds exact match of word in dict.txt, inputs whole line into dictionaryEntry
     Returns false if no match found
     */
    //static std::string findWordInDictionary(const std::string & english);

    //TODO: Implement these next
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