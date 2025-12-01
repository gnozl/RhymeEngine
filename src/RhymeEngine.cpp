//
// Created by Gerardo Gonzalez on 11/21/25.
//

#include "../include/RhymeEngine.h"

#include <fstream>
#include <sstream>
#include <algorithm>

RhymeEngine::RhymeEngine() = default;

RhymeEngine::~RhymeEngine() = default;

void RhymeEngine::runRhymeEngine() {
    //std::cout << "RhymeEngine::run()" << std::endl;

    std::ifstream textFileStream;
    if (!openTextFile(textFileStream)) {
        return;
    }

    Text text = createText(textFileStream);

    text.print();
    text.printIPA();

    textFileStream.close();
}

void RhymeEngine::createDictionary(const std::string & dictionaryFilePath) {
    std::ifstream dictionaryFile;
    dictionaryFile.open(dictionaryFilePath);
    if (!dictionaryFile.is_open()) {
        throw std::runtime_error("Unable to open dictionary file.");
    }
    unordered_map<string, pair<char, string>> dictionary;
    int count = 0;

    std::string nextLine;
    std::string firstWord;
    while (std::getline(dictionaryFile, nextLine)) {
        stringstream stream(nextLine);
        getline(stream, firstWord, ' ');
        ranges::transform(firstWord, firstWord.begin(), ::tolower); // all keys should be stored in lowercase
        std::string partOfSpeech;
        std::string pronunciation;
        getline(stream, partOfSpeech, ' ');
        getline(stream, pronunciation, '\r');
        std::erase(pronunciation, '/');
        pair entry = {partOfSpeech[0], pronunciation};
        dictionary.insert({firstWord, entry});
        count++;
    }
    cout << "Created dictionary from " << dictionaryFilePath << " with " << count << " entries." << endl;

    dictionaryFile.close();
    rhymeDictionary = dictionary;
}

bool RhymeEngine::openTextFile(std::ifstream & file) {
    //std::cout << "RhymeEngine::openFile()" << std::endl;

    std::cout << "Welcome to RhymeEngine!" << std::endl;
    std::cout << "Which .txt file would you like to open? ";
    string userInput;
    std::getline(std::cin, userInput);
    file.open("../addFilesHere/" + userInput + ".txt");
    while (!file.is_open()) {
        std::cout << "Unable to open file. Please put the correct .txt file in the RhymeEngine/addFilesHere/ folder." << std::endl;
        std::cout << "Please type a new file name, or type Q to quit: ";
        std::cin >> userInput;
        if (userInput == "Q" || userInput == "q") {return false;}
        file.open("../addFilesHere/" + userInput + ".txt");
        }
    std::cout << "File opened successfully." << std::endl;
    return true;
    }

Text RhymeEngine::createText(std::ifstream & inputFile) {
    //std::cout << "RhymeEngine::createText()" << std::endl;
    Text text;
    int wordAttempts = 0;
    int wordSuccess = 0;
    std::string nextLineFromInputFile;
    while (std::getline(inputFile, nextLineFromInputFile, '\n')) { // std::getline returns false at End of File
        Line newline;
        std::string nextWordString;
        for (char16_t c : {u'—', u'-', u'/'}) { // Replace certain characters with spaces
            std::replace(nextWordString.begin(), nextWordString.end(), c, u' ');
        }
        stringstream stream(nextLineFromInputFile);
        stream >> std::ws; // clear all leading whitespace so getline doesnt grab empty space
        while (std::getline(stream, nextWordString, ' ')) { // Returns false at end of stream
            if (nextWordString == " "){continue;}
            wordAttempts++;
            try {
                Word newWord = createWord(nextWordString);
                newline.addWord(newWord); // Add Word to Line object
                wordSuccess++;
            }
            catch (std::runtime_error & e) {
                std::cout << e.what() << std::endl;
                Word newWord("????", NO_POS, "");
                newline.addWord(newWord); // Add Empty Word to Line object
            }
        }
        // End of line stream
        text.addLine(newline);
    }
    std::cout << "Text file created: " << wordSuccess << "/" << wordAttempts << " words created." << std::endl;
    return text;
}  // End of File

Word RhymeEngine::createWord(std::string &english) {
    //cout << "Creating word: " << english << endl;

    std::string cleanKey = english;
    cleanKey.erase(ranges::remove_if(cleanKey, [](char c) {
        return !std::isalnum(c);
    }).begin(), cleanKey.end()); // remove anything that is not alpha-numeric

    ranges::transform(cleanKey, cleanKey.begin(), ::tolower);

    pair<char, string> dictionaryEntry = getDictionaryEntry(cleanKey);

    Word word(english, dictionaryEntry.first, dictionaryEntry.second);

    return word;
}

pair<char,string> RhymeEngine::checkForSuffixes(const std::string &key) {
    pair<char, string> dictionaryEntry{' '," "};
    std::vector<std::string> suffixes {"ies", "ied",  "ing", "ed", "es","ly", "y", "s", "d"};

    for (const string suffix : suffixes) {
        if (key.size() - suffix.size() > 1) {
            string substring = key.substr(key.size()-suffix.size(), key.size()-1);
            if (substring == suffix) { //if the end of the word matches a suffix
                string base_word = key.substr(0, key.size() - suffix.size()); // cut off the suffix
                if (suffix == "ies" || suffix == "ied") { // hurried
                    base_word += 'y'; //  hurr-> hurry
                }
                bool found = false;
                if (rhymeDictionary.contains(base_word)) {
                    dictionaryEntry = rhymeDictionary.at(base_word);
                    found = true;
                }
                if (!found) { //if the final two letters match (swimming -> swim)
                    if ((base_word[base_word.length()-1]) == base_word[base_word.length()-2]) {
                        base_word = base_word.substr(0, base_word.length()-2);
                        if (rhymeDictionary.contains(base_word)) {
                            dictionaryEntry = rhymeDictionary.at(base_word);
                            found = true;
                        }
                    }
                }

                //TODO: Add suffixes?
                if (found) {
                    if (suffix == "s" || suffix == "ies") {dictionaryEntry.second += 'z';} // dog -> dogs
                    else if ( suffix == "ied") {dictionaryEntry.second += 'd';} // hurry -> hurried
                    else if (suffix == "ing") {dictionaryEntry.second += "iN";} //box -> boxing
                    else if (suffix == "es") {dictionaryEntry.second += "Iz";} // box -> boxes
                    else if (suffix == "ly") {dictionaryEntry.first = 'v'; dictionaryEntry.second += "li";} //quick -> quickly
                    else if (suffix ==  "y") {dictionaryEntry.first = 'A'; dictionaryEntry.second += "i";} // jump -> jumpy
                    else if (suffix == "ed" || suffix == "d") {
                        char finalSound = dictionaryEntry.second[dictionaryEntry.second.size()-1];
                        if (finalSound == 'd' || finalSound == 't') {
                            dictionaryEntry.second += "Id"; // load -> loaded, lift -> lifted
                        } else {
                            dictionaryEntry.second += "d"; // sneeze -> sneezed, clothe -> clothed
                        }
                    }
                    return dictionaryEntry;
                }
            }
        }
    } // end of suffixes
    return dictionaryEntry;
}

pair<char, string> RhymeEngine::getDictionaryEntry(const std::string & key) {
    //std::cout << "RhymeEngine::getDictionaryEntry: " << key << std::endl;

    bool found = false;
    pair<char, string> dictionaryEntry;

    if (rhymeDictionary.contains(key)) {
        dictionaryEntry = rhymeDictionary.at(key);
        found = true;
    }


    if (!found) {
        dictionaryEntry = checkForSuffixes(key);
        if (dictionaryEntry != std::pair{' '," "}) {
            found = true;
        }
    }

    // if (!found) {
    //     //TODO: Ask user to manually input dictionary entries / user-created dictionary
    // }

    if (found) {return dictionaryEntry;}
    else {throw std::runtime_error("Failed to find dictionary entry for " + key);}
}

// std::vector<std::string> RhymeEngine::findRhymes(Word & word) {
//     std::vector<std::string> result;
//     //TODO: FIND RHYMES
//     return result;
// }
//
// bool RhymeEngine::isRhyme(Word & word1, Word & word2) {
//     bool result = false;
//     //TODO: Does it rhyme?
//     return result;
// }