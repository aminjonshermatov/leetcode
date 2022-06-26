#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int freq[52] = {0,};

        for (const auto ch : s) {
            if (ch < 'a') ++freq[ch - 'A'];
            else ++freq[26 + ch - 'a'];
        }

        int ans = 0;
        short anyOdd = 0;

        for (int i = 0; i < 52; ++i) {
            ans += freq[i] & (~0u << 1);
            anyOdd |= freq[i] & 1;
        }

        if (anyOdd) ++ans;

        return ans;
    }
};