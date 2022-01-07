#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        function<void(int, int)> check = [&s, &res](int l, int r) -> void {
            while (l >= 0 && r < s.size() && l <= r) {
                if (s[l--] != s[r++]) break;
                ++res;
            }
        };

        for (int i = 0; i < s.size(); ++i) {
            check(i, i);
            check(i, i + 1);
        }

        return res;
    }
};