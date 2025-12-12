# Checkpoint 2 Test Cases  
## Feature: Store Text as Objects  
### Test Setup  

**Test files:**   
`test/test_rhymeStrength.cpp`
`tests/test_highlight_rhymes.cpp`
 
Build system:  
`cmake`   

Run command:  

  `ctest --verbose`  
  `rhymetest1`  
  `rhymetest2`  
  `rhymetest3`   
or  
 `test_rhyme-colors`
  

### Test 1: rhymeStrength
-
**What it tests**:   
- Compares two words & returns a value based on how many matching phonemes  

**Expected result**:  
- Words created: bear / care / wolf / falling / calling
- care vs bear should returns 3  
- care vs wolf should returns 0  
- falling vs calling returns 5  

**Result**: ✅ Pass

### Test 2: test_rhyme_colors
-  
**What it tests**:  
- Reprints an input text with end rhymes in color  
- When all colors are used, reuses first colors  

**Expected result**:    
- Words that rhyme are printed in matching colors

**Result**: ✅ Pass

### CTest Output
- check colortestoutput.png in the docs folder