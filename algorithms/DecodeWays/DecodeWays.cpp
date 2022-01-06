#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || *s.begin() == '0') return 0;

        vector<int> dp(s.size() + 2, 0);
        dp[s.size()] = 1;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] <= '0' || s[i] > '9') continue;

            dp[i] += dp[i + 1];

            if (i + 1 < s.size() && (s[i] < '2' || s[i] == '2' && s[i + 1] < '7')) dp[i] += dp[i + 2];
        }

        return dp[0];
    }
};