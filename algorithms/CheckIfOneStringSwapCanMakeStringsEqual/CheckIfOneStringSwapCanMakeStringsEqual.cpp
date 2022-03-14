#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        auto notEq{0};

        pair<int, int> freq[26] = {{0, 0}};

        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) ++notEq;
            ++freq[s1[i] - 'a'].first;
            ++freq[s2[i] - 'a'].second;
        }

        for (int i = 0; i < 26; ++i) {
            if (freq[i].first != freq[i].second) return false;
        }

        return notEq == 0 or notEq == 2;
    }
};