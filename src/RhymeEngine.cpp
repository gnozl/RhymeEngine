//
// Created by Gerardo Gonzalez on 11/21/25.
//

#include "../include/RhymeEngine.h"

#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

RhymeEngine::RhymeEngine() = default;

RhymeEngine::~RhymeEngine() = default;

void RhymeEngine::run() {
    std::ifstream dictionaryFile;
    loadDictionary(dictionaryFile);

    std::ifstream textFile;
    if (!openFile(textFile)) {
        return;
    }

    Text text;
    if (!createText(textFile, text, dictionaryFile)) {
        std::cout << "Text file creation failed." << std::endl;
        return;
    }
    std::cout << "Text file successfully created." << std::endl;

    text.print();
    text.printIPA();

    textFile.close();
    dictionaryFile.close();
}

void RhymeEngine::loadDictionary(std::ifstream & file) {
    file.open("../include/test_dict.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open dictionary file.");
    }
}

bool RhymeEngine::openFile(std::ifstream & file) {
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

bool RhymeEngine::createText(std::ifstream & file, Text & text, std::ifstream & dictionary) {
    bool success = false;
    std::string nextLineOfDictionary;
    while (std::getline(file, nextLineOfDictionary)) { // std::getline returns false at End of File
        Line newLine{};
        std::string nextWordString;
        stringstream stream(nextLineOfDictionary); // each line of dict.txt formatted as "xxxxx y zzzzz" X is english spelling, Y is a single char part of speech, Z is pronunciation
        while (stream >> nextWordString) { // Returns false at end of stream
            Word newWord;
            if (!createWord(nextWordString, newWord, dictionary)) { //
                std::cout << "Failed to create word: " + nextWordString << std::endl;
            }
            else {
                std::cout << "Word " << newWord.getEnglish() << " created successfully." << std::endl;
                newLine.addWord(newWord); // Add Word to Line object
                }
            }
        // End of line stream
        text.addLine(newLine);
        success = true;
        }
    return success;
}  // End of File

bool RhymeEngine::createWord(std::string &english, Word &word, std::ifstream &dictionary) {

    std::string dictionaryEntry;
    std::stringstream stream("");

    if (!findWordInDictionary(english, dictionary, dictionaryEntry)) {
        return false;
    }
    stream << dictionaryEntry;
    stream >> english;

    char pos;
    stream >> pos;

    std::string pronunciation;
    stream >> pronunciation;

    word.setEnglish(english);
    word.setPronunciation(pronunciation);
    word.setPartOfSpeech(pos);

    return true;
}

bool RhymeEngine::findWordInDictionary(const std::string & english, std::ifstream & dictionary, std::string & dictionaryEntry) {

    bool found = false;
    std::vector<std::string> suffixes {"s", "es", "ing", "ed", "ly"};

    string line;
    while (std::getline(dictionary, line)){ // TODO:Binary search instead?
        stringstream stream("");
        stream.clear();
        stream.seekg(0);

        std::string dictionaryWord;
        char dictionaryPOS;
        std::string dictionaryPronunciation;

        stream << line; // Pull first word from line into stream
        stream >> dictionaryWord;
        // https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
        ranges::transform(dictionaryWord, dictionaryWord.begin(),
                          [](unsigned char c){ return std::tolower(c); });
        stream << line;
        stream >> dictionaryPOS;
        stream << line;
        stream >> dictionaryPronunciation;

        if (dictionaryWord == english) { // Perfect match found
            found = true;
            dictionaryEntry += dictionaryWord;
            dictionaryEntry += " ";
            dictionaryEntry += dictionaryPOS;
            dictionaryEntry += " ";
            dictionaryEntry += dictionaryPronunciation;
        }

        if (!found && dictionaryWord[dictionaryWord.length()-1]=='y') { // if word ends in y
            for (std::string suffix : {"ies", "ied"}) {
                std::string wordWithSuffix;
                wordWithSuffix = dictionaryWord.substr(0, dictionaryWord.length()-1);
                wordWithSuffix += suffix;

                if (wordWithSuffix == english) {
                    found = true;
                    dictionaryEntry = wordWithSuffix;
                    dictionaryEntry.append(" ");
                    dictionaryEntry += dictionaryPOS;
                    dictionaryEntry.append(" ");
                    dictionaryEntry += dictionaryPronunciation;
                    if (suffix == "ies") {dictionaryEntry.append("z");} //  spy -> spies
                    if (suffix == "ied") {dictionaryEntry.append("d");} //  spy -> spied
                    break;
                }
            }
        }

        if (!found) {
            std::string wordWithSuffix;
            for (const std::string& suffix : suffixes) {
                wordWithSuffix = dictionaryWord + suffix;
                if (wordWithSuffix == english) {
                    found = true;
                    dictionaryEntry.append(wordWithSuffix);
                    dictionaryEntry.append(" ");
                    dictionaryEntry += dictionaryPOS;
                    dictionaryEntry.append(" ");
                    dictionaryEntry += dictionaryPronunciation;
                    if (suffix == "s") {dictionaryEntry.append("z");} // dog -> dogs
                    if (suffix == "es") {dictionaryEntry.append("Iz");} // fox -> foxes
                    if (suffix == "ing") {dictionaryEntry.append("iN");} // jump -> jumping
                    if (suffix == "ed") {
                        if (wordWithSuffix[wordWithSuffix.length()-3] == 't' || wordWithSuffix[wordWithSuffix.length()-3] == 'd') {
                            dictionaryEntry.append("Id"); // band -> banded
                        } else {
                            dictionaryEntry.append("t"); // jump -> jumped
                        }
                    }
                    if (suffix == "ly") {dictionaryEntry.append("li");} // quick -> quickly
                    break;
                }
            }
        }

        if (found) {
            dictionary.clear();
            dictionary.seekg(0);
            return true;
        }
    }
    std::cout << "Unable to find word " << english << " in dictionary." << std::endl;
    // Move the read pointer to the beginning of the file
    dictionary.clear();
    dictionary.seekg(0);
    return false; // Could not find word in dictionary
}

std::vector<std::string> RhymeEngine::findRhymes(Word & word) {
    std::vector<std::string> result;
    //TODO: FIND RHYMES
    return result;
}

bool RhymeEngine::isRhyme(Word & word1, Word & word2) {
    bool result = false;
    //TODO: Does it rhyme?
    return result;
}
