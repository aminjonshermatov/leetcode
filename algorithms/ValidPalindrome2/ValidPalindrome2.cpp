#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        const int n = static_cast<int>(s.size());

        const function<bool(int, int)> check = [&](int l, int r) -> bool {
            while (l < r) {
                if (s[l] != s[r]) return false;
                ++l;
                --r;
            }

            return true;
        };

        for (int l = 0, r = n - 1; l < r; ++l, --r) {
            if (s[l] != s[r]) {
                return check(l + 1, r) or check(l, r - 1);
            }
        }

        return true;
    }
};