//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_PHONEMES_H
#define RHYMEENGINE_PHONEMES_H
#include <unordered_map>

enum PHONEME {
    // VOWELS
    EH,    //[-] schwa / lazy vowel

    AA,    //[A] sounds like the "a" in far, bob
    EE,    //[E] sounds like the "e" in "red"
    II,    //[i] sounds like the "e" in "see"
    UU,    //[u] sounds like the "oo" in "too"

    AH,    //[&] sounds like the "a" in "dab"
    UH,    //[^] sounds like the "a" in "cup"
    UR,    //[@] sounds like the "u" in "burn"
    IH,    //[I] sounds like the "i" in "hid"
    UE,    //[U] sounds like the "oo" in "book"

    EU,    //[y] sounds like the "eu" in "cordon bleu"
    YU,    //[Y] sounds like the "u" in "Dubois"
    AW,    //[O] sounds like the "o" in "dog"
    // DIPHTHONGS
    AI,    //[1] sounds like the "i" in "ice"
    EI,    //[2] sounds like the "a" in "day"
    OI,    //[3] sounds like the "oi" in "oil"
    AU,    //[4] sounds like the "ow" in "how"
    OU,    //[5] sounds like the "o" in "boat"
    EY,    //[6] sounds like the "a" in "air"
    // END OF VOWELS

    // CONSONANTS
    BB,    //[b] sounds like the "b" in "nab"
    DD,    //[d] sounds like the "d" in "pod"
    PP,    //[p] sounds like the "p" in "imp"
    TT,    //[t] sounds like the "t" in "tap"
    GG,    //[g] sounds like the "g" in "fig"
    KK,    //[k] sounds like the "c" in "act"

    TH,    //[T] sounds like the "th" in "bath"
    DH,    //[D] sounds like the "th" in "that"
    FF,    //[f] sounds like the "f" in "elf"
    VV,    //[v] sounds like the "v" in "average"
    SS,    //[s] sounds like the "s" in "sip"
    ZZ,    //[z] sounds like the "z" in "zoo"

    SH,    //[S] sounds like the "sh" in "she"
    ZH,    //[Z] sounds like the "s" in "vision"
    DJ,    //[J] sounds like the "g" in "vegetably"
    CH,    //[C] sounds like the "ch" in "ouch"

    HH,    //[h] sounds like the "h" in "had"
    XH,    //[x] sounds like the "ch" in "Bach"
    WW,    //[w] sounds like the "w" in "win"
    HW,    //[W] sounds like the "w" in "white"

    JJ,    //[j] sounds like the "y" in "you"
    LL,    //[l] sounds like the "l" in "ail"
    MM,    //[m] sounds like the "m" in "aim"
    NN,    //[n] sounds like the "n" in "and"
    NG,    //[N] sounds like the "n" in "Francoise", ng in bang.

    RR,    //[r] sounds like the "r" in "red"
    RA,    //[R] sounds like the "r" in "rojo"

    NULL_PHONEME // DO NOT USE
    };

const std::unordered_map<char, PHONEME> charToPhone = {
    {'-', EH},

    {'A', AA},
    {'E', EE},
    {'i', II},
    {'u', UU},

    {'&', AH},
    {'^', UH},
    {'@', UR},
    {'I', IH},
    {'U', UE},

    {'y', EU},
    {'Y', YU},
    {'O', AW},

    {'1', AI},
    {'2', EI},
    {'3', OI},
    {'4', AU},
    {'5', OU},
    {'6', EY},

    {'b', BB},
    {'d', DD},
    {'p', PP},
    {'t', TT},
    {'g', GG},
    {'k', KK},

    {'T', TH},
    {'D', DH},
    {'f', FF},
    {'v', VV},
    {'s', SS},
    {'z', ZZ},

    {'S', SH},
    {'Z', ZH},
    {'J', DJ},
    {'C', CH},

    {'h', HH},
    {'x', XH},
    {'w', WW},
    {'W', HW},

    {'j', JJ},
    {'l', LL},
    {'m', MM},
    {'n', NN},
    {'N', NG},

    {'r', RR},
    {'R', RA}
};

/*
    // from https://stevehanov.ca/blog/index.php?id=8
    //this is what they use in a char * array[]
    // for use with old_dict.txt

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