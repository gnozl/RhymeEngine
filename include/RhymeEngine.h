//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_RHYMEENGINE_H
#define RHYMEENGINE_RHYMEENGINE_H
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Colors.h"
#include "Text.h"
#include "Word.h"
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
    COLOR next_rhyme_color = RED;
    vector<int> syllableArray;
    vector<int> rhymeArray;
    unordered_map<string, pair<char, string>> rhymeDictionary;
    std::vector<COLOR> color_vec {
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        RED_BRIGHT,
        GREEN_BRIGHT,
        YELLOW_BRIGHT,
        BLUE_BRIGHT,
        MAGENTA_BRIGHT,
        CYAN_BRIGHT
    };

public:

    RhymeEngine();
    ~RhymeEngine();

    // Turns dict.txt into an unordered map - sets up rhymeDictionary member variable
    void createDictionary(const std::string& dictionaryFilePath = "../src/dict.txt");

    void runRhymeEngine(std::string textFile = "default");

    // Asks user for file to open; Returns true if successful
    bool openTextFile(std::ifstream & file, const std::string & textFile);

    Text createText(const std::string &file);

    // Using selected filestream, create Text object, using dictionary; Returns text object
    Text createText(std::ifstream & inputFile);

    /* Edits Word object using data from dictionary
      Throws ERROR on failure
     */
    Word createWord(std::string &english) const;

    /* Finds exact match of word in dict.txt, inputs whole line into dictionaryEntry
     ERROR if no match found
     */
    [[nodiscard]] pair<char, string> getDictionaryEntry(const std::string& key) const;
    /* If basic getDictionaryEntry search fails, run this
     * Returns {' ', " "} if no match found
    */
    [[nodiscard]] pair<char, std::string> checkForSuffixes(const std::string & key) const;

    [[nodiscard]] bool isVowel(char phone) const;

    // Returns the number of matching phonemes, beginning at the end of the word
    [[nodiscard]] int rhymeStrength (const Word & word1, const Word & word2) const;
    // Returns the edit distance between two strings
    [[nodiscard]] int editDistanceSpaceOptimized(string str1, string str2) const;

    void setEndRhymes(Text & text);
    void setAllRhymes(Text & text);
    COLOR setNewColor(Word & word);


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