# Checkpoint 1 Test Cases  
## Feature: Store Text as Objects  
### Test Setup  

**Test files:**   
 `tests/test_word.cpp`  
 `tests/test_line.cpp`  
 `tests/test_text.cpp`
 
Build system:  
`cmake`   

Run command:  
  `
  ctest --verbose
  `

### Test 1: Word
-
**What it tests**:   
- Stores an input word into a Word object 
- Converts the input into the correct phonemes
- Prints the Word object correctly
- Counts the syllables in the word

**Expected result**:  
- Word is created from the text using constructor
- Word is printed using std::cout << override
- Syllables are counted using Word::isVowel()

**Result**: ✅ Pass

### Test 2: Edge Case
-
**What it tests**: [e.g.,
"Creating a recipe with no ingredients"]
-
**Expected result**: Recipe is created with empty ingredients list
-
**Result**: ✅ Pass
### Test 3: Boundary Conditions
-
**What it tests**: [e.g.,
"Setting rating to min and max values"]
-
**Expected result**: Rating is correctly set to 1 and 5
-
**Result**: ✅ Pass
### CTest Output
```
```
```
[Paste your ctest --verbose output here]