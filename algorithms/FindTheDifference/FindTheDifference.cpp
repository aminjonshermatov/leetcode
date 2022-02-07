#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int counter[26][2] = {{0, 0}};

        for (const auto ch : s) ++counter[ch - 'a'][0];
        for (const auto ch : t) ++counter[ch - 'a'][1];

        for (int i = 0; i < 26; ++i) {
            if (counter[i][0] != counter[i][1]) return i + 'a';
        }

        return {};
    }
};