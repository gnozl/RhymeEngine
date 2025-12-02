# Checkpoint 1 Reflection
## What I Implemented
- **RhymeEngine::CreateDictionary()** -- This function reads the dict.txt file which contains 110,000+ lines, and puts each line into an unordered map.   
  
- **RhymeEngine::CreateText(filename)** -- This function tries opening filename.txt, then uses the dictionary unordered_map to convert every word in the file into a Word object. The Words are put into Lines, which are put into the final Text object, which is returned.  

## Challenges I Faced
- The initial dictionary (old_dict.txt in the project) -- had to be slightly modified so that each phoneme was a single character instead of two. I used numbers and special characters for this. (ae = @, oi = 2, etc).  
- At first, I tried reading from an open filestream for every dictionary lookup, but that was very slow. Using an unordered_map was much faster.  
- Lots of words are not in the dictionary, especially variations of words. "dog" is in there, but not "dogs", "jump" but not "jumping/jumped" etc. -- I had to add checkForSuffixes() to find variants of words and modify the pronunciation.  
- Handling whitespace & nonalphanumeric characters caused lots of issues -- I added a lot of cleanup code to skip over or ignore strange words. I can't delete them because the original text still has to be printed without changes. All capital letters were made lowercase internally, etc.   

## What I Learned
- Mostly how to handle streams and read files.  
- std::erase(), std::transform(), std::replace() were all very useful for cleaning up strings   
- Working directly from files is much slower than storing the file in a data structure first  
- Tests were very helpful for debugging, especially basic stuff  

## Testing Results
- first test: can't find very first word "The" -> add capitalization fix
- 2nd test: can't find "jumps" -> add suffixes
- 3rd test: can't find "dogs." -> remove grammatical marks
- 4th test: can't find "  " -> getline() reads after finding a single delimiter character, even if the next is the same character -> fix: make sure to remove all leading whitespaces  

## Questions for Next Checkpoint
- I think I should make the unordered_map<>>rhymeDictionary member static & create it as soon as a RhymeEngine instance is created, so you can't run run() without running createDictionary() first, but the program won't compile whenever I put createDictionary() in the RhymeEngine() constructor. 
- How do i handle different text encodings? basic ASCII works, but UTF-8 -- i get crashes when i try to put certain characters into char or std::string  

## Time Spent
10 - 15 hours probably.