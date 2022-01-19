#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        pair<int, int> freq[26] = {{0, 0}};

        for (const auto ch : s) ++freq[ch - 'a'].first;
        for (const auto ch : t) ++freq[ch - 'a'].second;

        for (size_t i{0}; i < 26; ++i) {
            if (freq[i].first != freq[i].second) return false;
        }

        return true;
    }
};