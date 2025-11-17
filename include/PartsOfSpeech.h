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
| D      | Quantifier / Qualifier |
*/

enum POS {
    NOUN,
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
    DETERMINER
};

#endif //RHYMEENGINE_PARTSOFSPEECH_H