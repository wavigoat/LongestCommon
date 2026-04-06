#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "usage:\n";
        cout << argv[0] << " <k> <len>\n";
        cout << "where 'k'   is the number of characters,\n";
        cout << "and   'len' is the length of the strings A and B\n";
        return 1;
    }

    int k = stoi(argv[1]);
    int len = stoi(argv[2]);
    if (k < 1 || len < 1) {
        return 1;
    }

    // randomization boilerplate
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<int> value_dist(1, 10);   // randomly pick values of chars
    uniform_int_distribution<int> char_dist(0, k - 1); // randomly pick chars for A and B

    // K
    cout << k << "\n";

    // x1 v1, x2 v2, ...
    for (int i = 0; i < k; i++) {
        char x1 = 'a' + i;
        int v1 = value_dist(g);
        cout << x1 << " " << v1 << "\n";
    }

    // A, B
    for (int i = 0; i < 2; i++) {
        for (int i = 0; i < len; i++) {
            char c = 'a' + char_dist(g);
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}
