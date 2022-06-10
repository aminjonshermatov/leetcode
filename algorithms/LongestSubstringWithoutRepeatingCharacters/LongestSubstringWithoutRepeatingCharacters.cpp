#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> hh;
        int ans = 0;

        for (int l = 0, r = 0; r < s.size(); ++r) {
            if (hh.count(s[r]) > 0) l = max(l, hh[s[r]] + 1);
            hh[s[r]] = r;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};