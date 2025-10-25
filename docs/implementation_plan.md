# Rhyme Engine Implementation Plan

## Feature 1: Load/Save text from a file

**Trigger**: Program starts & asks user for file name  
**Input Needed**: filename  
**Implementation Flow**:  
1. main()
   - Show initial message
   - Prompt user for text title
   - Prompt user for filename
   - Call rhymeEngine.CreateText(title, filename);
   
2. CreateText()
   - Create Text object
   - Open filename in stream
   - Open IPA dictionary in stream
   - Read filename using std::getline()
   
3. while loop through each word
   - Create new Line object
   - For each word in line:
   - Initialize Word Object
   - Call rhymeEngine.findIPA(word)
   - if no match, ask user for help?
   - 
   - Convert the IPA to enum PHONEME
   - Store IPA in word.ipa
   - Call Word.addPhoneme()
   - Count syllables, add to Line.syllables 
   - Store Word object in Line
   - At end of line, repeat loop
   - At end of file, Text constructor completes  
  
4. close streams  
   - close file  
   - close ipa dictionary

**Data Modified**  
- New Text Created
- Line objects added to Text Object
- Word objects added to Line Objects


## Identify Rhymes in Text

**Trigger** Text finished initialization  
**Input Needed**: None  
**Implementation Flow**:  
1. Find rhymes
   - For each final Word in each line:
   - For each line, get final syllable (list of phonemes)
   - Call rhymeEngine.matchRhymeToColors(finalSyllable)
   - If no rhymes exist in rhymeEngine.rhymes:
   - Create new PHONEME,COLOR pair
   - Set Word.color to matching color

## Display rhymes in different colors  
- Loop thru Text
- Loop thru each Line
- For each Word, print it in its color

## Count syllables in a line of text  
- for each line, run Line::setRhythm()
- Loop thru each Word in Line
- Loop thru chars in the IPA of the word
- vowelReached = false //syllables are separated by vowel sounds
- if stress marker is read (, or `), bool stress = true
- if char == vowel, vowelReached = true, syllable++, rhythm.pushback(stress)  
- reset stress to false

## Grade text based on consistent rhyme/meter  
- Make an SyllablesArray from each Line.numberOfSyllables
- Make an array of each final Word rhyme / COLOR
- Check for regular patterns in each array
- Check for a pattern after combining arrays
- Give points if patterns are found (not sure how to do this yet)

## Example:

I want to be the very best,  
Like no one ever was.  
To catch them is my real test,  
To train them is my cause.  
I will travel across the land,  
Searching far and wide.  
Teach Pokémon to understand,  
The power that's inside.  

SyllablesArray = [8, 6, 8, 6, 8, 6, 8, 6]  
RhymeArray     = [1, 2, 1, 2, 3, 4, 3, 4]  
