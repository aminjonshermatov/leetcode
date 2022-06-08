#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        bool isPal = true;
        for (int l = 0, r = s.size() - 1; l < r && isPal; ++l, --r) {
            isPal = s[l] == s[r];
        }

        return isPal ? 1 : 2;
    }
};