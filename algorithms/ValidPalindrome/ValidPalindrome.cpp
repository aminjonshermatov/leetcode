#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int l = 0, r = static_cast<int>(s.size()) - 1; l < r; ++l, --r) {
            while (l < r && !isalpha(s[l]) && !isdigit(s[l])) ++l;
            while (l < r && !isalpha(s[r]) && !isdigit(s[r])) --r;

            if (tolower(s[l]) != tolower(s[r])) return false;
        }

        return true;
    }
};
