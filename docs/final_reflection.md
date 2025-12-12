## Gerardo Gonzalez
## Rhyme Engine

`https://github.com/gnozl/RhymeEngine`

## Project Summary:
This program takes in a text file, then highlights rhyming words.

# Features:
1. Create Dictionary & Search for words in Dictionary
2. Create Text object from .txt file
3. Find rhyming words in Text & reprint it with rhymes highlighted

# Feature 1 Description:
- Read dict.txt file, one line a time.
- Each line gets added to an unsorted_map as {word, {part of speech, pronunciation}}
- When searching for a word, check for matching key.
- If key not found, check if word has suffix and search for that instead. 

# Feature 2 Description:
- Read user-selected file, converting each word into a Word object.
- If word doesn't exist, handle error and create empty word object.

# Feature 3 Description:
- Compare the pronuncations of each Word in the Text.
- If the rhyme strength matches sufficiently with something else, change their colors to match. 
- Print out the original text, but with colored text instead.


What it does well:
- It very quickly creates & displays the results. 
- It finds definitions of 100,000+ words without having to search.
- It can deal with strange words & grammatical marks without errors.


## What Remains

#Missing features:
- Comparing words based on definitions (word2vec)
- Suggesting rhymes to the user.

Bugs & issues:  
The project works, but is very dependant on the pronunciation database being accurate. 
For example, "flower" and "hour" do not rhyme in the dictionary.
It fails to find some words when suffixes edit the spelling -- ie set -> setting (because of the extra t, can't find sett)
If a word is too short, it will fail to rhyme with anything. (in should rhyme with bin)


## Time Estimate  
- word2vec -> Not sure. Should be fairly quick once I figure out what part of the word2vec code to copy over.
- Suggesting Rhymes -> A couple hours. Will probably need to create a pre-made file with rhymes in it, so that searching a 100,000+ line file multiple times is not needed. Also, need to clean up the dictionary.txt file first.

| Remaining Item | Time Estimate | Priority |
|-----------------------|---------------|-------------|
| word2vec semantic similarity | 2-3 hours | Must-have |
| Suggesting Rhymes | 3 hours | Nice-to-have|
| Suffix bug fixes | an hour | Must-have |


## What I Learned

- Concepts: Reading Files, storing and searching large numbers of objects
- Hardest Part: Reading an unexpected character, making sure I was using only words and not nonsense text
- What I would do differently: Spend less time obsessing over niche bugs
- Most proud of: How quick and simple the main function is.
- How has my understanding of data structures changed: The most important part seems to be keeping all the data organized in a way that is easy to work with. 


## Time Log
Planning and Design: 3-4 hours
Implementation: 3-4 hours
Testing and Debugging: 10+ hours
Documentation: 1 hours
Total: ~20 hours