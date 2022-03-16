#include "bits/stdc++.h"

using namespace std;

class Solution {
    inline auto isAlphaNum(char ch) -> bool const { return (ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z') or (ch >= '0' and ch <= '9'); };

public:
    bool isPalindrome(string s) {
        const int n = s.size();

        for (int l = 0, r = n - 1; l < r; ++l, --r) {
            while (l < n and not isAlphaNum(s[l])) ++l;
            while (r >= 0 and not isAlphaNum(s[r])) --r;

            if (l >= r) break;

            auto lhs{s[l]};
            if (lhs >= 'A' and lhs <= 'Z') lhs = 'a' + (lhs - 'A');

            auto rhs{s[r]};
            if (rhs >= 'A' and rhs <= 'Z') rhs = 'a' + (rhs - 'A');

            if (lhs != rhs) return false;
        }

        return true;
    }
};