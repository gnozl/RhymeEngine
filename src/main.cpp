#include <fstream>
#include <iostream>

#include "../include/phonemes.h"
#include "../include/RhymeEngine.h"


int main()
{
    //TODO: Ask user for text file name
    //TODO: Load text file
    //TODO: Parse text file into Text, Line, Word objects
    //TODO: Find rhymes inside text / end of lines
    //TODO: Print out the text, with rhymes highlighted

    std::cout << "Intro message\n";

    RhymeEngine rhymeEngine;

    const std::string filename = rhymeEngine.getFileNameFromUser();
    rhymeEngine.loadTextFile(filename);
    std::string title;
    std::cin >> title;
    Text text = rhymeEngine.createText(title, filename); //TODO: This does a lot of stuff

    for (Line * line : text.getLines()) {
        Word * temp_word = line->getFinalWord();
        rhymeEngine.matchRhymeToColors(temp_word);
        rhymeEngine.printColorText();

        }

    return 0;
}