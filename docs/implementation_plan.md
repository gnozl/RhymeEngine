# Rhyme Engine Implementation Plan

## Feature 1: Load/Save text from a file

**Trigger**: Program starts & asks user for file name  
**Input Needed**: filename  
**Implementation Flow**:  
- In main, after an initial message:
- Prompt user for text title
- Prompt user for filename
- Call rhymeEngine.CreateText(title, filename);
- add Line object to Text
- loop through each word in the text file:
- Word Object Initialization:
- for each word, call rhymeEngine.findIPA(word)
- convert the IPA to enum PHONEME
- call Word.addPhoneme()
- count syllables 
- store Word object in Line
- At each line end, create new line, continue looping
- At file end, end loop  

**Data Modified**  
- New Text Created
- Line objects added to Text Object
- Word objects added to Line Objects


## Identify Rhymes in Text

**Trigger** Text finished initialization  
**Input Needed**: None  
**Implementation Flow**:  
- For each final Word in each line:
- Call rhymeEngine.matchRhymeToColors(word)
- If no rhymes exist in rhymeEngine.rhymes:
- Call 

## Display rhymes in different colors  
## Count syllables in a line of text  
## Grade text based on consistent rhyme/meter  