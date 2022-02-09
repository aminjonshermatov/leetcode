#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> h_map;

        for (const auto ch : s) ++h_map[ch];

        int res = 0;
        bool hasOneLength = false;

        for (const auto [_, v] : h_map) {
            res += (v >> 1) << 1;

            if (v & 1) hasOneLength = true;
        }

        if (hasOneLength) ++res;

        return res;
    }
};