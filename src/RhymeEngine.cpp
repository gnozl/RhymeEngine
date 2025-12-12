//
// Created by Gerardo Gonzalez on 11/21/25.
//

#include "../include/RhymeEngine.h"

#include <fstream>
#include <sstream>
#include <algorithm>

RhymeEngine::RhymeEngine() = default;

RhymeEngine::~RhymeEngine() = default;

void RhymeEngine::runRhymeEngine(std::string textFile) {
    std::cout << "Welcome to RhymeEngine!" << std::endl;
    string fileToOpen = textFile;
    if (textFile == "default") { // if run without parameters, defaults to asking user for a file
        std::cout << "Which .txt file would you like to open? ";
        std::getline(std::cin, fileToOpen);
    } else {fileToOpen = textFile;}

    std::ifstream textFileStream;
    if (!openTextFile(textFileStream, fileToOpen)) {
        return; // if not file given, or user types Q, quit program
    }

    Text text = createText(textFileStream);
    setRhymes(text);

    text.print();

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
    while (std::getline(dictionaryFile, nextLine)) { // for each line in dict.txt
        stringstream stream(nextLine); // read line
        getline(stream, firstWord, ' '); // grab first word in line as key
        ranges::transform(firstWord, firstWord.begin(), ::tolower); // all keys should be stored in lowercase
        std::string partOfSpeech;
        std::string pronunciation;
        getline(stream, partOfSpeech, ' '); // second word is the part of speech
        getline(stream, pronunciation, '\r'); //3rd word is the pronunciation; the dictionary file has /r at the end of lines, before the \n character??
        std::erase(pronunciation, '/'); //TODO: maybe edit the dictionary file directly and remove these? i don't know exactly what they signify
        pair entry = {partOfSpeech[0], pronunciation};
        dictionary.insert({firstWord, entry}); // dictionary key is string, value is a pair<char,string>
        count++;
    }
    cout << "Created dictionary from " << dictionaryFilePath << " with " << count << " entries." << endl;

    dictionaryFile.close();
    rhymeDictionary = dictionary;
}

bool RhymeEngine::openTextFile(std::ifstream & file, const std::string & textFile) {
    //std::cout << "RhymeEngine::openFile()" << std::endl;

    file.open("../addFilesHere/" + textFile + ".txt");
    while (!file.is_open()) {
        std::cout << "Unable to open file. Please put the correct .txt file in the RhymeEngine/addFilesHere/ folder." << std::endl;
        std::cout << "Please type a new file name, or type Q to quit: ";
        std::string input;
        std::cin >> input;
        if (input == "Q" || input == "q") {return false;}
        file.open("../addFilesHere/" + input + ".txt");
        }
    std::cout << "File opened successfully." << std::endl;
    return true;
    }

Text RhymeEngine::createText(const string & file) {
    ifstream fileStream;
    fileStream.open(file);
    if (!fileStream.is_open()) {
        throw std::runtime_error("Unable to open file.");
    }
    Text text = createText(fileStream);
    fileStream.close();
    return text;
}

Text RhymeEngine::createText(std::ifstream & inputFile) {
    //std::cout << "RhymeEngine::createText()" << std::endl;
    Text text;
    int wordAttempts = 0;
    int wordSuccess = 0;
    std::string nextLineFromInputFile;

    while (std::getline(inputFile, nextLineFromInputFile, '\n')) { // std::getline returns false at End of File
        Line newline;

        for (char c : { u'-', u'/'}) { // Replace certain characters with spaces
            std::replace(nextLineFromInputFile.begin(), nextLineFromInputFile.end(), c, ' ');
        }
        stringstream stream(nextLineFromInputFile);
        stream >> std::ws; // clear all leading whitespace so getline doesnt grab empty space

        std::string nextWordString;
        while (std::getline(stream, nextWordString, ' ')) { // Returns false at end of stream
            if (nextWordString == " "){continue;} // skip empty spaces, TODO: maybe use std::ws instead to skip?
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
        if (newline.getNumberOfWords() > 0) {
            text.addLine(newline); //add line to text
        }
    }
    std::cout << "Text file created: " << wordSuccess << "/" << wordAttempts << " words created." << std::endl;
    return text;
}  // End of File

Word RhymeEngine::createWord(std::string &english) {
    //cout << "Creating word: " << english << endl;

    std::string cleanKey = english;
    // https://stackoverflow.com/questions/6319872/how-to-strip-all-non-alphanumeric-characters-from-a-string-in-c
    cleanKey.erase(ranges::remove_if(cleanKey, [](char c) {
        return !std::isalnum(c);
    }).begin(), cleanKey.end()); // remove anything that is not alpha-numeric

    ranges::transform(cleanKey, cleanKey.begin(), ::tolower); // make lowercase

    pair<char, string> dictionaryEntry = getDictionaryEntry(cleanKey);

    Word word(english, dictionaryEntry.first, dictionaryEntry.second);

    return word;
}

pair<char, string> RhymeEngine::getDictionaryEntry(const std::string & key) const {
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

pair<char,string> RhymeEngine::checkForSuffixes(const std::string &key) const {
    pair<char, string> dictionaryEntry{' '," "};
    //TODO: add more suffixes, clean this up
    //TODO: currently cannot find: happiest, happily
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

bool RhymeEngine::isVowel(char phone) const {
    if (!charToPhone.contains(phone)) {
        return false;
    }
    PHONEME phoneme = charToPhone.at(phone);
    if (phoneme > 0 && phoneme < BB) return true;
    return false;
}

int RhymeEngine::rhymeStrength(const Word &word1, const Word &word2) const {
    string ipa1 = word1.getPronunciation();
    reverse(ipa1.begin(), ipa1.end());
    string ipa2 = word2.getPronunciation();
    reverse(ipa2.begin(), ipa2.end());

    int counter = 0;
    for (int i=0; i < min(ipa1.size(), ipa2.size()); i++) {
        if (ipa1[i] == ipa2[i]) {
            counter++;
            if (isVowel(ipa1[i])){
                counter++;
            }
        }
        if (i > counter + 2) {
            return 0;
        }
    }
    return counter;
}

// C++ program to calculate minimum edit distance
// https://www.geeksforgeeks.org/cpp/edit-distance-in-cpp/
// TODO: Use this somehow?
int RhymeEngine::editDistanceSpaceOptimized(string str1, string str2) const {

    // Length of the first string
    int m = str1.length();
    // Length of the second string
    int n = str2.length();

    // Create two vectors to store the current and previous
    // rows of the DP table
    vector<int> prev(n + 1), curr(n + 1);

    // Initialize the prev vector with base case values
    for (int j = 0; j <= n; j++) {
        // Edit distance when str1 is empty
        prev[j] = j;
    }

    // Iterate over each character of str1
    for (int i = 1; i <= m; i++) {
        // Initialize the first element of curr
        curr[0] = i;

        // Compute edit distance for each substring of str2
        for (int j = 1; j <= n; j++) {
            // If characters match, no new operation needed
            if (str1[i - 1] == str2[j - 1]) {
                curr[j] = prev[j - 1];
            }
            else {
                // Consider all three operations: insert,
                // remove, replace
                curr[j] = 1
                          + min(min(prev[j], curr[j - 1]),
                                prev[j - 1]);
            }
        }

        // Move to the next row by swapping prev and curr
        prev = curr;
    }

    // Return the minimum edit distance
    return prev[n];
}

void RhymeEngine::setRhymes(Text & text) {
    vector<Word *> ending_words;
    for (Line & line : text.getLines()) {
        Word & word = line.getWords().back();
        ending_words.push_back(&word);
        }
    for (Word * word1 : ending_words) {
        if (word1->getColor() != NONE) {
            continue;
        }
        setNewColor(*word1);
        for (Word * word2 : ending_words) {
            if (rhymeStrength(*word1, *word2) > 2) {
                word2->setColor(word1->getColor());
            }
        }
    }
}

COLOR RhymeEngine::setNewColor(Word &word) {
    word.setColor(next_rhyme_color);

    auto index = std::find(color_vec.begin(), color_vec.end(), next_rhyme_color);
    if (index != color_vec.end() && std::next(index) != color_vec.end()) {
        next_rhyme_color = *std::next(index);
    } else {
        // Cycle back to the first element or handle end-of-enum
        next_rhyme_color = color_vec.front();
    }
    return word.getColor();
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