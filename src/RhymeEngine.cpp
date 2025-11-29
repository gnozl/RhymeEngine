//
// Created by Gerardo Gonzalez on 11/21/25.
//

#include "../include/RhymeEngine.h"

#include <fstream>
#include <sstream>
#include <algorithm>

RhymeEngine::RhymeEngine(const std::string& dictionaryFilePath) {
    rhymeDictionary = createDictionary(dictionaryFilePath);
};

RhymeEngine::~RhymeEngine() = default;

void RhymeEngine::run() {
    //std::cout << "RhymeEngine::run()" << std::endl;

    std::ifstream textFileStream;
    if (!openFile(textFileStream)) {
        return;
    }

    Text text = createText(textFileStream);

    text.print();
    text.printIPA();

    textFileStream.close();
}

unordered_map<std::string, pair<std::string, std::string>> RhymeEngine::createDictionary(const std::string & dictionaryFilePath) {
    std::ifstream dictionaryFile;
    dictionaryFile.open(dictionaryFilePath);
    if (!dictionaryFile.is_open()) {
        throw std::runtime_error("Unable to open dictionary file.");
    }
    unordered_map<string, pair<string, string>> dictionary;
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
        getline(stream, pronunciation, ' ');
        pair entry = {partOfSpeech, pronunciation};
        dictionary.insert({firstWord, entry});
        count++;
    }
    cout << "Created dictionary from " << dictionaryFilePath << " with " << count << " entries." << endl;

    dictionaryFile.close();
    return dictionary;
}

bool RhymeEngine::openFile(std::ifstream & file) {
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
    while (std::getline(inputFile, nextLineFromInputFile)) { // std::getline returns false at End of File
        Line newline;
        std::string nextWordString;
        stringstream stream(nextLineFromInputFile);
        while (std::getline(stream, nextWordString)) { // Returns false at end of stream
            Word newWord;
            wordAttempts++;
            try {
                newWord = createWord(nextWordString);
                wordSuccess++;
            }
            catch (std::runtime_error & e) {
                std::cout << e.what() << std::endl;
                newWord.setEnglish("????");
                newWord.setPartOfSpeech(NO_POS);
                newWord.setPronunciation("");
            }
            newline.addWord(newWord); // Add Word to Line object
        }
        // End of line stream
        text.addLine(newline);
    }
    std::cout << "Text file created: " << wordSuccess << "/" << wordAttempts << " words created." << std::endl;
    return text;
}  // End of File

Word RhymeEngine::createWord(std::string &english) {

    pair<string, string> dictionaryEntry = getDictionaryEntry(english);
    std::stringstream stream(dictionaryEntry.second + " "); //make sure dictionary entry has space at end

    std::string key;
    getline(stream, key, ' ');

    std::string pos;
    getline(stream, pos, ' ');

    std::string pronunciation;
    getline(stream, pronunciation, ' ');

    Word word;
    word.setEnglish(english);
    word.setPronunciation(pronunciation);
    char posChar = pos[0];
    word.setPartOfSpeech(posChar);

    return word;
}

pair<string,string> RhymeEngine::checkForSuffixes(const std::string &key) {
    pair<string, string> dictionaryEntry;
    std::vector<std::string> suffixes {"s", "es", "ing", "ed", "ly", "y", "ies", "ied"};
    // TODO: Check for word + suffixes
    return dictionaryEntry;
}

pair<string, string> RhymeEngine::getDictionaryEntry(const std::string & key) {
    std::string lowercaseKey = key;
    ranges::transform(lowercaseKey, lowercaseKey.begin(), ::tolower);

    bool found = false;
    pair<string, string> dictionaryEntry;

    if (rhymeDictionary.contains(lowercaseKey)) {
        dictionaryEntry = rhymeDictionary.at(lowercaseKey);
        found = true;
    }

    if (!found) {
        dictionaryEntry = checkForSuffixes(lowercaseKey);
        if (!dictionaryEntry.second.empty()) {
            found = true;
        }
    }

    // if (!found) {
    //     //TODO: Ask user to manually input dictionary entries / user-created dictionary
    // }

    if (found) {return dictionaryEntry;}
    else {throw std::runtime_error("Failed to find dictionary entry for " + key);} // Return empty string as failure state
}

// std::string RhymeEngine::findWordInDictionary(const std::string & english) {
//
//     bool found = false;
//     std::vector<std::string> suffixes {"s", "es", "ing", "ed", "ly"};
//
//     string line;
//     while (std::getline(dictionary, line)){ // TODO: Implement Binary search
//         line+=" "; //Add whitespace to end of line for parsing
//         std::stringstream stream;
//
//         std::string dictionaryWord;
//         std::string dictionaryPOS;
//         std::string dictionaryPronunciation;
//
//         stream << line; // Pull first word from line into stream
//         stream >> dictionaryWord;
//
//         stream << line;
//         stream >> dictionaryPOS;
//
//         stream << line;
//         stream >> dictionaryPronunciation;
//
//         // https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
//         ranges::transform(dictionaryWord, dictionaryWord.begin(),
//                           [](unsigned char c){ return std::tolower(c); });
//
//         if (dictionaryWord == english) { // Perfect match found
//             found = true;
//             dictionaryEntry += dictionaryWord;
//             dictionaryEntry += " ";
//             dictionaryEntry += dictionaryPOS;
//             dictionaryEntry += " ";
//             dictionaryEntry += dictionaryPronunciation;
//         }
//
//         if (!found && dictionaryWord[dictionaryWord.length()-1]=='y') { // if word ends in y
//             for (std::string suffix : {"ies", "ied"}) {
//                 std::string wordWithSuffix;
//                 wordWithSuffix = dictionaryWord.substr(0, dictionaryWord.length()-1);
//                 wordWithSuffix += suffix;
//
//                 if (wordWithSuffix == english) {
//                     found = true;
//                     dictionaryEntry = wordWithSuffix;
//                     dictionaryEntry.append(" ");
//                     dictionaryEntry += dictionaryPOS;
//                     dictionaryEntry.append(" ");
//                     dictionaryEntry += dictionaryPronunciation;
//                     if (suffix == "ies") {dictionaryEntry.append("z");} //  spy -> spies
//                     if (suffix == "ied") {dictionaryEntry.append("d");} //  spy -> spied
//                     break;
//                 }
//             }
//         }
//
//         if (!found) {
//             std::string wordWithSuffix;
//             for (const std::string& suffix : suffixes) {
//                 wordWithSuffix = dictionaryWord + suffix;
//                 if (wordWithSuffix == english) {
//                     found = true;
//                     dictionaryEntry.append(wordWithSuffix);
//                     dictionaryEntry.append(" ");
//                     dictionaryEntry += dictionaryPOS;
//                     dictionaryEntry.append(" ");
//                     dictionaryEntry += dictionaryPronunciation;
//                     if (suffix == "s") {dictionaryEntry.append("z");} // dog -> dogs
//                     if (suffix == "es") {dictionaryEntry.append("Iz");} // fox -> foxes
//                     if (suffix == "ing") {dictionaryEntry.append("iN");} // jump -> jumping
//                     if (suffix == "ed") {
//                         if (wordWithSuffix[wordWithSuffix.length()-3] == 't' || wordWithSuffix[wordWithSuffix.length()-3] == 'd') {
//                             dictionaryEntry.append("Id"); // band -> banded
//                         } else {
//                             dictionaryEntry.append("t"); // jump -> jumped
//                         }
//                     }
//                     if (suffix == "ly") {dictionaryEntry.append("li");} // quick -> quickly
//                     break;
//                 }
//             }
//         }
//
//         if (found) {
//             dictionary.clear();
//             dictionary.seekg(0);
//             return true;
//         }
//     }
//     std::cout << "Unable to find word " << english << " in dictionary." << std::endl;
//     // Move the read pointer to the beginning of the file
//     dictionary.clear();
//     dictionary.seekg(0);
//     return false; // Could not find word in dictionary
// }

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
