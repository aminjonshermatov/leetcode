#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        pair<int, int> freq[26] = {{0, 0}};

        for (const auto ch : ransomNote) ++freq[ch - 'a'].first;
        for (const auto ch : magazine) ++freq[ch - 'a'].second;

        for (size_t i{0}; i < 26; ++i) {
            if (freq[i].first > freq[i].second) return false;
        }

        return true;
    }
};