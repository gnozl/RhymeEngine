# Rhyme Engine

A command-line program for finding and highlighting rhymes in a text

## Features

- Load/Save text from a file
- Identifies rhymes within a text
- Display rhymes in different colors
- Count syllables in a line of text
- Grade text based on consistent rhyme/meter


## Building

```
mkdir build
cd build
cmake ..
cmake --build .

```

## Usage
```
./RhymeEngine
```

## Author
```
Gerardo Gonzalez - CIS 25 Final Project
```

## Current Status
**Implemented Features**:  
- ✅ Feature 1: RhymeEngine::CreateDictionary() -- Creates an unordered map from dict.txt  
- ✅ Feature 2: RhymeEngine::CreateWord(string) -- Creates a Word object using dictionary from string  
- ✅ Feature 3: RhymeEngine::CreateText -- Creates a Text object from a txt file  
- ✅ Feature 4: Text::PrintIPA -- Prints the entire Text object  

**In Progress**:  
- ⏳ Feature 5: FindRhymes
- ⏳ Feature 6: Print Rhyming Words in matching colors  
- ⏳ Feature 7: Ask user to provide dictionary entry when missing

**Planned**:  
- 📋 Feature 7: Match words based on definitions  
- 📋 Feature 8: Suggest words that are a closer rhyme/meaning match  

**Known Issues**:
- Lots of words missing from dictionary
- Odd characters that do not fit in char cause crash