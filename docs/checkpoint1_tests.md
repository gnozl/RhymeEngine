# Checkpoint 1 Test Cases
## Feature: Store Text as Objects
### Test Setup
- Test file:
  `tests/test_text_storage.cpp
  `
- Build system: CMake with CTest
- Run command:
  `
  ctest --verbose
  `
### Test 1: Normal Operation
-
**What it tests**:   
- Stores an input word into a Word object 

**Expected result**:  
- Word is created using pronunciations in dict.txt

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