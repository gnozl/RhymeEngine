#include <fstream>
#include <iostream>

#include "../include/Phonemes.h"
#include "../include/RhymeEngine.h"

//For printing colors to Windows terminal
#ifdef _WIN32
#include <windows.h>

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define DISABLE_NEWLINE_AUTO_RETURN  0x0008

void activateVirtualTerminal()
{
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode( handleOut , &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;
    SetConsoleMode( handleOut , consoleMode );
}
#endif

int main()
{
#ifdef _WIN32
    activateVirtualTerminal();
#endif
    //TODO: Ask user for text file name
    //TODO: Load text file
    //TODO: Parse text file into Text, Line, Word objects
    //TODO: Find rhymes inside text / end of lines
    //TODO: Print out the text, with rhymes highlighted

    RhymeEngine rhymeEngine;
    rhymeEngine.run();

    // std::cout << "Intro message\n";

    // const std::string filename = rhymeEngine.getFileNameFromUser();
    // rhymeEngine.loadTextFile(filename);
    // std::string title;
    // std::cin >> title;
    // Text text = rhymeEngine.createText(title, filename); //TODO: This does a lot of stuff


    // for (Line * line : text.getLines()) {
    //     Word * temp_word = line->getFinalWord();
    //     rhymeEngine.matchRhymeToColors(temp_word);
    //     rhymeEngine.printColorText();
    //
    //     }

    return 0;
}