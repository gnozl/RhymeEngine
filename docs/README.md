# Rhyme Engine

A command-line program for finding and highlighting rhymes in a text


## Current Status
**Implemented Features**:
- ✅ Feature 1: RhymeEngine::CreateDictionary() -- Creates an unordered map from dict.txt
- ✅ Feature 2: RhymeEngine::CreateWord(string) -- Creates a Word object using dictionary from string
- ✅ Feature 3: RhymeEngine::CreateText -- Creates a Text object from a txt file
- ✅ Feature 4: Text::PrintIPA -- Prints the entire Text object
- ✅ Feature 5: FindRhymes
- ✅ Feature 6: Print Rhyming Words in matching colors
- 
**In Progress**:
- 📋 Feature 7: Match words based on definitions
- ⏳ Feature 8: Ask user to provide dictionary entry when missing

**Planned**:

- 📋 Feature 9: Suggest words that are a closer rhyme/meaning match

**Known Issues**:
- Lots of words missing from dictionary
- Some words, like flower & hour, do not rhyme in dictionary
- Suffixes that double a consonant (fit -> fitting) are not found correctly
- UTF-8 characters do not fit in char & cause crash


## Building

```
mkdir build
cd build
cmake ..
cmake --build .

```

## Usage
add a .txt file to /addFilesHere folder, or use one of the test files already there
```
./rhyme_engine  
<FILENAME>
```

## Author
```
Gerardo Gonzalez - CIS 25 Final Project
```
