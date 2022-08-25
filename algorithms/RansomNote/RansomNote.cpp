#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int fr[26] = {0};
        for (auto ch : magazine) ++fr[ch - 'a'];

        for (auto ch : ransomNote) if (--fr[ch - 'a'] < 0) return false;
        return true;
    }
};