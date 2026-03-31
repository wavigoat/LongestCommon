#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int K;
    if (!(cin >> K)) return 0;

    unordered_map<char, int> values;
    for (int i = 0; i < K; ++i) {
        //c = character, v = corresponding value
        char c;
        int v;
        cin >> c >> v;
        values[c] = v;
    }

    string A, B;
    cin >> A >> B;
    return 0;
}