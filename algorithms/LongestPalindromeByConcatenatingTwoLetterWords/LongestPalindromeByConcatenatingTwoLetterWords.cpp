#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        const int N(words.size());

        map<string, int> mp;
        for (auto &w : words) ++mp[w];

        int ans = 0;
        bool used_center = false;
        for (auto &[w, c] : mp) {
            if (w[0] != w[1]) {
                auto rev = w;
                reverse(rev.begin(), rev.end());

                auto mn = min(c, mp[rev]);
                ans += mn * 4;
                mp[rev] = 0;
                c = 0;
            } else {
                if ((c & 1) && !used_center) ans += 2, used_center = true;
                ans += c >> 1 << 2;
            }

        }

        return ans;
    }
};