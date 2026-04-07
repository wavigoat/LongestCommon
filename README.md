# HVLCS

Name: Kaitlyn Tran  
UFID: 79518935  

Name: May Macler  
UFID: 26170596  

## Files
`src/main.cpp`: The source code for algorithms  


## Compiling
To compile the matcher, use a C++ compiler (like g++):  
```
g++ -std=c++11 -o test ./src/main.cpp
```
To test with input, run:  
```
./test ./input/example.in
```
Your output should match what is written in example.out
  
### Timing
To time the results, also pass `time` after the input file name:  
```
./test ./input/5_100.in time
```
This will print the runtime (in microseconds, averaged across 10 runs), followed by the normal output.

## Assumptions
The program needs O(nm) space to store the long long DP table. 
Input strings should only contain characters defined in the initial K alphabet lines.

## Questions
### 1. Empirical Comparison
![Graph of runtimes](graph.png)

### 2. Recurrence Equation

OPT(i, j) =
- **0**, if i = 0 or j = 0
- **v(a_i) + OPT(i-1, j-1)**, if a\_i = b\_i
- **max(OPT(i-1, j), OPT(i, j-1))**, otherwise

With either i = 0 or j = 0, we have the base case where no subsequence can exist between the two strings (one or both of the prefixes is empty), so the highest value must therefore be 0.  

If the two characters in consideration are equal, then we have found part of a common subsequence, and thus the value of OPT(i, j) will be the value of this character, plus the value of the of the two prefixes up to this character.  

Otherwise (i.e., when the two characters in consideration are not equal), including either a\_i or b\_i had no effect on the value of the subsequence. Thus, we simply take the larger of the OPT(i-1, j) and OPT(i, j-1), as these two cases are both subsets of the current case, OPT(i, j).  


### 3. Big-Oh
Here `A[1]` means "the first character in string A".

```
Input: strings A, B

let n = length(A)
let m = length(B)

let dp[n+1][m+1] = 0 (all values initialized to 0)

for i = 1 .. n
    for j = 1 .. m
        if A[i] == B[j]
            dp[i][j] = value(A[i]) + dp[i-1][j-1]
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        endif
    endfor
endfor

return dp[n][m]
```

This algorithm is O(nm), with `n` and `m` being the lengths of strings A and B respectively. This clearly follows from the fact that the code is two nested loops running `n` and `m` times each.
