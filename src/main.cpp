#include "../include/RhymeEngine.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

//For printing colors to Windows terminal
// #ifdef _WIN32
// #include <windows.h>
//
// #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
// #define DISABLE_NEWLINE_AUTO_RETURN  0x0008
//
// void activateVirtualTerminal()
// {
//     HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
//     DWORD consoleMode;
//     GetConsoleMode( handleOut , &consoleMode);
//     consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
//     consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;
//     SetConsoleMode( handleOut , consoleMode );
// }
// #endif

int main()
{
// #ifdef _WIN32
//     activateVirtualTerminal();
// #endif

    RhymeEngine engine;
    engine.createDictionary();
    while (true) {
        engine.runRhymeEngine();
        std::cout << "Would you like to run Rhyme Engine again? (Y/N): )";
        std::string input;
        std::getline(std::cin, input);
        if (input != "Y" && input != "y" && input != "yes") {
            break;
        }
    }
    return 0;
}