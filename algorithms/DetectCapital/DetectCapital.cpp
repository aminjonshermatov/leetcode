#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        return all_of(word.begin(), word.end(), [](auto ch) { return isupper(ch); })
               || all_of(word.begin(), word.end(), [](auto ch) { return islower(ch); })
               || (all_of(next(word.begin()), word.end(), [](auto ch) { return islower(ch); }) && isupper(word.front()));
    }
};