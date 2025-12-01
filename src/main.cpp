#include "../include/RhymeEngine.h"

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
    //TODO: Find rhymes inside text / end of lines
    //TODO: Print out the text, with rhymes highlighted

    RhymeEngine engine;
    engine.createDictionary();
    engine.runRhymeEngine("test/test1");

    return 0;
}