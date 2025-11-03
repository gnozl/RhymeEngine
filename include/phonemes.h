//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_PHONEMES_H
#define RHYMEENGINE_PHONEMES_H
#include <map>

//TODO: use real IPA pronunciation symbols?
//TODO: combine similar sounds?
//TODO: convert chars from dict.txt to enum
//TODO: separate vowels & consonants

enum PHONEME {
    // from https://stevehanov.ca/blog/index.php?id=8
    AE,    //[æ] sounds like the "a" in "dab"
    EY,    //[ ] sounds like the "a" in "air"
    YR,    //[ ] sounds like the "ir" glide in "tire"
    AH,    //[ ] sounds like the "a" in "ado", cup
    UE,    //[ ] sounds like the "u" in "burn"
    AA,    //[a] sounds like the "a" in "ami", far, bob
    AU,    //[ ] sounds like the "ow" in "how"
    DH,    //[ð] sounds like the "th" in "the"
    EH,    //[e] sounds like the "e" in "red"
    IH,    //[ı] sounds like the "i" in "hid"
    NG,    //[ ] sounds like the "n" in "Francoise", ng in bang.
    AW,    //[ ] sounds like the "o" in "dog"
    OI,    //[ ] sounds like the "oi" in "oil"
    ER,    //[ ] sounds like the "r" in "Der"
    SH,    //[ ] sounds like the "sh" in "she"
    TH,    //[ ] sounds like the "th" in "bath"
    UH,    //[ ] sounds like the "oo" in "book"
    YU,    //[ ] sounds like the "u" in "Dubois"
    DS,    //[ ] sounds like the "s" in "vision"
    AI,    //[ ] sounds like the "i" in "ice"
    BB,    //[b] sounds like the "b" in "nab"
    DD,    //[d] sounds like the "d" in "pod"
    DJ,    //[ ] sounds like the "g" in "vegetably"
    EI,    //[ei] sounds like the "a" in "day"
    FF,    //[f] sounds like the "f" in "elf"
    GG,    //[g] sounds like the "g" in "fig"
    HH,    //[ ] sounds like the "h" in "had"
    HW,    //[ ] sounds like the "w" in "white"
    II,    //[i] sounds like the "e" in "see"
    JJ,    //[j] sounds like the "y" in "you"
    KK,    //[k] sounds like the "c" in "act"
    LL,    //[l] sounds like the "l" in "ail"
    MM,    //[m] sounds like the "m" in "aim"
    NN,    //[n] sounds like the "n" in "and"
    OU,    //[ ] sounds like the "o" in "boat"
    PP,    //[p] sounds like the "p" in "imp"
    RR,    //[ ] sounds like the "r" in "ire"
    SS,    //[s] sounds like the "s" in "sip"
    TT,    //[t] sounds like the "t" in "tap"
    CH,    //[ ] sounds like the "ch" in "ouch"
    OO,    //[u] sounds like the "oo" in "too"
    VV,    //[v] sounds like the "v" in "average"
    WW,    //[w] sounds like the "w" in "win"
    XH,    //[x] sounds like the "ch" in "Bach"
    EU,    //[ ] sounds like the "eu" in "cordon bleu"
    ZZ,    //[z] sounds like the "z" in "zoo"
    };

const std::map<PHONEME, std::string> phoneString = {
    {AE, "AE"},
    {EY, "EY"},
    {YR, "YR"},
    {AH, "AH"},
    {UE, "UE"},
    {AA, "AA"},
    {AU, "AU"},
    {DH, "DH"},
    {EH, "EH"},
    {IH, "IH"},
    {NG, "NG"},
    {AW, "AW"},
    {OI, "OI"},
    {ER, "ER"},
    {SH, "SH"},
    {TH, "TH"},
    {UH, "UH"},
    {YU, "YU"},
    {DS, "DS"},
    {AI, "AI"},
    {BB, "BB"},
    {DD, "DD"},
    {DJ, "DJ"},
    {EI, "EI"},
    {FF, "FF"},
    {GG, "GG"},
    {HH, "HH"},
    {HW, "HW"},
    {II, "II"},
    {JJ, "JJ"},
    {KK, "KK"},
    {LL, "LL"},
    {MM, "MM"},
    {NN, "NN"},
    {OU, "OU"},
    {PP, "PP"},
    {RR, "RR"},
    {SS, "SS"},
    {TT, "TT"},
    {CH, "CH"},
    {OO, "OO"},
    {VV, "VV"},
    {WW, "WW"},
    {XH, "XH"},
    {EU, "EU"},
    {ZZ, "ZZ"},
};

/*
    // from https://stevehanov.ca/blog/index.php?id=8
    //this is what they use in a char * array[]

    "&",    //[æ] sounds like the "a" in "dab"
    "(@)",  //[ ] sounds like the "a" in "air"
    "-",    //[ ] sounds like the "ir" glide in "tire"
    "@",    //[ ] sounds like the "a" in "ado", cup
    "@r",   //[ ] sounds like the "u" in "burn"
    "A",    //[a] sounds like the "a" in "ami", far, bob
    "AU",   //[ ] sounds like the "ow" in "how"
    "D",    //[ð] sounds like the "th" in "the"
    "E",    //[e] sounds like the "e" in "red"
    "I",    //[ı] sounds like the "i" in "hid"
    "N",    //[ ] sounds like the "n" in "Francoise", ng in bang.
    "O",    //[ ] sounds like the "o" in "dog"
    "Oi",   //[ ] sounds like the "oi" in "oil"
    "R",    //[ ] sounds like the "r" in "Der"
    "S",    //[ ] sounds like the "sh" in "she"
    "T",    //[ ] sounds like the "th" in "bath"
    "U",    //[ ] sounds like the "oo" in "book"
    "Y",    //[ ] sounds like the "u" in "Dubois"
    "Z",    //[ ] sounds like the "s" in "vision"
    "aI",   //[ ] sounds like the "i" in "ice"
    "b",    //[b] sounds like the "b" in "nab"
    "d",    //[d] sounds like the "d" in "pod"
    "dZ",   //[ ] sounds like the "g" in "vegetably"
    "eI",   //[ei] sounds like the "a" in "day"
    "f",    //[f] sounds like the "f" in "elf"
    "g",    //[g] sounds like the "g" in "fig"
    "h",    //[ ] sounds like the "h" in "had"
    "hw",   //[ ] sounds like the "w" in "white"
    "i",    //[i] sounds like the "e" in "see"
    "j",    //[j] sounds like the "y" in "you"
    "k",    //[k] sounds like the "c" in "act"
    "l",    //[l] sounds like the "l" in "ail"
    "m",    //[m] sounds like the "m" in "aim"
    "n",    //[n] sounds like the "n" in "and"
    "oU",   //[ ] sounds like the "o" in "boat"
    "p",    //[p] sounds like the "p" in "imp"
    "r",    //[ ] sounds like the "r" in "ire"
    "s",    //[s] sounds like the "s" in "sip"
    "t",    //[t] sounds like the "t" in "tap"
    "tS",   //[ ] sounds like the "ch" in "ouch"
    "u",    //[u] sounds like the "oo" in "too"
    "v",    //[v] sounds like the "v" in "average"
    "w",    //[w] sounds like the "w" in "win"
    "x",    //[x] sounds like the "ch" in "Bach"
    "y",    //[ ] sounds like the "eu" in "cordon bleu"
    "z",    //[z] sounds like the "z" in "zoo"
    };
*/
#endif //RHYMEENGINE_PHONEMES_H