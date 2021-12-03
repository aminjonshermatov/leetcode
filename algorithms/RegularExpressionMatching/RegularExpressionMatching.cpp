#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = static_cast<int>(s.size()),
            pLen = static_cast<int>(p.size());

        vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= pLen; ++i) {
            if (i > 1 && p[i - 1] == '*' && dp[0][i - 2]) dp[0][i] = true;
        }

        for (int i = 1; i <= sLen; ++i) {
            for (int j = 1; j <= pLen; ++j) {
                if (p[j - 1] == '*' && j > 1) {
                    dp[i][j] = dp[i][j - 2];

                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
                else if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            }
        }

        return dp[sLen][pLen];
    }
};