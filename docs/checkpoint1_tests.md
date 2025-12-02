# Checkpoint 1 Test Cases  
## Feature: Store Text as Objects  
### Test Setup  

**Test files:**   
 `tests/test_rhyme_engine.cpp`  
 `tests/test_enums.cpp`  
 `tests/test_word.cpp`  
 `tests/test_dictionary.cpp`  
 
Build system:  
`cmake`   

Run command:  
  `
  ctest --verbose
  `

### Test 1: Word
-
**What it tests**:   
- Creates dictionary unordered_map from dict.txt
- Creates a Text object from a file
- Searches dictionary for pronunciations
- Prints the Text object (words & pronunciations) correctly


**Expected result**:  
- Text is created using RhymeEngine::createText(filename)  
- Each Word is created successfully  
- Text is printed out again  

**Result**: ✅ Pass

### Test 2: Empty File  
-  
**What it tests**:  
- Creating a text from an empty file  

**Expected result**:   
- Empty Text is made without crashing  

**Result**: ✅ Pass  

### Test 3: Nonsense file
-
**What it tests**: 
- Creating a Text from nonsense file  

**Expected result**: 
Fails to create Words, prints out ???? instead  

**Result**: ✅ Pass  

### Test 4: Complicated File
-
**What it tests**:
- file includes nonalphanumeric characters
- file includes words with suffixes not in dict.txt
- file includes empty lines

**Expected result**:
- Fails to create Words, prints out ??? for english and ???? for pronunciation instead  

**Result**: ✅ Pass

### CTest Output
```
test 4
    Start 4: RhymeEngineTest

4: Test command: /Users/gerardo/CIS25/RhymeEngine/build/test_rhyme_engine
4: Working Directory: /Users/gerardo/CIS25/RhymeEngine/build
4: Test timeout computed to be: 10000000
4: ==TEST MAKE TEXT FROM FILES==
4: Created dictionary from ../src/dict.txt with 110021 entries.
4: Testing basic file ...
4: Welcome to RhymeEngine!
4: File opened successfully.
4: Text file created: 9/9 words created.
4: the quick brown fox 
4: jumps over the lazy dog 
4: D^ kwIk br4n fAks 
4: J^mpz '5v^r D^ 'l2zi dOg 
4: ✓ Basic file test passed
4: 
4: Testing empty file...
4: Welcome to RhymeEngine!
4: File opened successfully.
4: Text file created: 0/0 words created.
4: ✓ Empty file test passed
4: 
4: Testing nonsense file...
4: Welcome to RhymeEngine!
4: File opened successfully.
4: Failed to find dictionary entry for blahblahthisisnotawordm
4: Failed to find dictionary entry for asdfasdf
4: Failed to find dictionary entry for 234567
4: Text file created: 0/3 words created.
4: ???? ???? ???? 
4: ??? ??? ??? 
4: ✓ Nonsense file input passed
4: 
4: Testing complicated file ...
4: Welcome to RhymeEngine!
4: File opened successfully.
4: Text file created: 11/11 words created.
4: tHe quick! brown foxes jumping 
4: 
4: over THE thirty four lazy dogs??? 
4: D^ kwIk br4n fAksIz J^mpiN 
4: 
4: '5v^r D^ 'T@rti f5r 'l2zi dOgz 
4: ✓ Complicated file input passed
4/4 Test #4: RhymeEngineTest ..................   Passed    0.31 sec

100% tests passed, 0 tests failed out of 4

Total Test time (real) =   0.94 sec