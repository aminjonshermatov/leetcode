#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        for (const auto ch : s) ++freq[ch - 'a'];

        for (size_t i{0}; i < s.size(); ++i) {
            if (freq[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};