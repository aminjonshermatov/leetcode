#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(),
            lRes = 0,
            rRes = 0;

        function<void(int, int)> compute = [&s, &lRes, &rRes](int l, int r) -> void {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l > rRes - lRes) {
                    lRes = l;
                    rRes = r;
                }
                --l;
                ++r;
            }
        };

        for (int k = 0; k < len; ++k) {
            compute(k, k);
            compute(k, k + 1);
        }

        return s.substr(lRes, rRes - lRes + 1);
    }
};