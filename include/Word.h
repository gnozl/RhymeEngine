//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_WORD_H
#define RHYMEENGINE_WORD_H
#include <string>

class Word {
private:
    std::string english;
    std::string ipa_pronunciation;
    int syllables;

public:
    Word();
    ~Word();


};

#endif //RHYMEENGINE_WORD_H
