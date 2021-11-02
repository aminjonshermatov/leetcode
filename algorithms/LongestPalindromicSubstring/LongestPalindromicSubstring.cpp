#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int len = s.size();

        for (int k = 0; k < len; ++k) {
            int l, r;
            l = r = k;
            while (l >= 0 && r < len && s[l] == s[r]) {
                if (r - l + 1 > res.size()) {
                    res = s.substr(l, r - l + 1);
                }
                --l;
                ++r;
            }

            l = k;
            r = k + 1;
            while (l >= 0 && r < len && s[l] == s[r]) {
                if (r - l + 1 > res.size()) {
                    res = s.substr(l, r - l + 1);
                }
                --l;
                ++r;
            }
        }

        return res;
    }
};