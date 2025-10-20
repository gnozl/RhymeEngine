# Rhyme Engine Implementaton Plan

## Feature 1: Convert Text to IPA

**Trigger**: Program starts & asks user for file name
**Input Needed**: filename
**Implementation Flow**:
1. In main, after an initial message:
- Prompt user for text title
- Prompt user for filename
- Call rhymeEngine.CreateText(title, filename);
- add Line object to Text
- loop through each word in the text file:
- Word Object Initialization:
- for each word, call rhymeEngine.findIPA(word)
- convert the IPA to enum PHONEME
- call Word.setPhonemes()
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
1. For each final Word in each line:
- Call rhymeEngine.matchRhymeToColors(word)
- If no rhymes exist in rhymeEngine.rhymes:
- Call 