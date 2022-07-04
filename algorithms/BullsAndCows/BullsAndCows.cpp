#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        const int n(secret.size());

        int f1[10] = {0,}, f2[10] = {0,};
        int b = 0, c = 0;

        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) ++b;
            else {
                ++f1[secret[i] - '0'];
                ++f2[guess[i] - '0'];
            }
        }

        for (int i = 0; i < 10; ++i) c += min(f1[i], f2[i]);

        return to_string(b) + "A" + to_string(c) + "B";
    }
};