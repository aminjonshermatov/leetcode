#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[52] = {0,};

        for (auto ch : s) ++freq[ch - 'a'];
        for (auto ch : t) ++freq[ch - 'a' + 26];

        for (int i = 0, sh = 26; i < 26; ++i) {
            if (freq[i] != freq[sh + i]) return false;
        }

        return true;
    }
};
