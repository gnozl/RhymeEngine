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
    std::string filename; // For save/load operations
    std::vector<std::string> rhymes;
    std::vector<std::tuple<PHONEME, COLOR>> rhymeColors;

public:
    RhymeEngine();
    ~RhymeEngine();

    void run();
    std::string getFileNameFromUser();
    std::ifstream loadTextFile(std::string fileName);

    Text createText();
    std::string findIPA(std::string word);

    std::vector<std::string> findRhymes(Word * word);
    bool isRhyme(Word * word1, Word * word2);

    std::string convertWordToIPA(std::string string);

    bool saveTextFile(const std::string& newFileName);

    void matchRhymeToColors(Word * word);
    void printColorText();

};

#endif //RHYMEENGINE_RHYMEENGINE_H