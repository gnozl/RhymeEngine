//
// Created by Gerardo Gonzalez on 11/16/25.
//

#ifndef RHYMEENGINE_PARTSOFSPEECH_H
#define RHYMEENGINE_PARTSOFSPEECH_H

/*
| N      | Noun                   |
| h      | Hyphenated Noun        |
| p      | Plural Noun            |
| r      | Pronoun                |
| A      | Adjective              |
| V      | Verb                   |
| v      | Adverb                 |
| i      | Intransitive Verb      |
| t      | Transitive Verb        |
| !      | Interjection           |
| P      | Preposition            |
| C      | Conjunction            |
| D      | Determiner             |
*/

enum POS {
    NOUN,
    HYPHENATED,
    PLURAL,
    PRONOUN,
    ADJECTIVE,
    VERB,
    ADVERB,
    INTRANSITIVE,
    TRANSITIVE,
    INTERJECTION,
    PREPOSITION,
    CONJUNCTION,
    DETERMINER,
    NO_POS,
};

const std::unordered_map<char, POS> charToPOS = {
    {'N', NOUN},
    {'h', HYPHENATED},
    {'p', PLURAL},
    {'r', PRONOUN},
    {'A', ADJECTIVE},
    {'V', VERB},
    {'v', ADVERB},
    {'i', INTRANSITIVE},
    {'t', TRANSITIVE},
    {'!', INTERJECTION},
    {'P', PREPOSITION},
    {'C', CONJUNCTION},
    {'D', DETERMINER}
};

#endif //RHYMEENGINE_PARTSOFSPEECH_H