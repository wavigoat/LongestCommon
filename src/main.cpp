#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <fstream>

using namespace std;

/**
 1. Define OPT:
    OPT(i, j) is max total value of common subsequence between prefix A[1...i] and B[1...j].
 2. Define helper functions:
    v(char c): Returns integer value assigned to char c (handled by values.at(c))
 3. Recursive function for OPT:
    If A[i] == B[j]:  
        OPT(i, j) = OPT(i-1, j-1) + v(A[i])
    Else:
        OPT(i, j) = max(OPT(i-1, j), OPT(i, j-1))
 */

vector<vector<long long>> computeWeightedLCSValue(const string& A, const string& B, unordered_map<char, int>& values) {
    int n = A.length();
    int m = B.length();

    /**
     4. Data Structures:
        D array of size (n+1) x (m+1) to store calculated OPT values.
        Initialization: Fill table with 0 - base case
     */

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // General case:
            if (A[i - 1] == B[j - 1]) {
                // Char match: diagonal + value
                char matchingChar = A[i - 1];
                int charVal = values.at(matchingChar); 
                dp[i][j] = dp[i - 1][j - 1] + charVal;
            } else {

                // No match: take max of excluding one character from A or B
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            }
        }
    }

    return dp;
}

string backtrackLCS(const string& A, const string& B, const vector<vector<long long>>& dp) {
    string result = "";
    int i = A.length();
    int j = B.length();

    // start from bottom-right and go towards top-left
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            result += A[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file_path>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << argv[1] << endl;
        return 1;
    }

    int K;
    if (!(inputFile >> K)) return 0;

    unordered_map<char, int> values;
    for (int i = 0; i < K; ++i) {
        //c = character, v = corresponding value
        char c;
        int v;
        inputFile >> c >> v;
        values[c] = v;
    }

    string A, B;
    if (!(inputFile >> A >> B)) return 0;

    auto dpTable = computeWeightedLCSValue(A, B, values);

    long long maxValue = dpTable[A.length()][B.length()];
    string lcsString = backtrackLCS(A, B, dpTable);

    cout << maxValue << endl;
    cout << lcsString << endl;

    return 0;
}