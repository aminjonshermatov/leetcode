#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount = 0;

        for (const auto ch : word) {
            if (ch >= 'A' and ch <= 'Z') ++upperCount;
        }

        return upperCount == word.size() or upperCount == 0 or (upperCount == 1 and word[0] >= 'A' and word[0] <= 'Z');
    }
};