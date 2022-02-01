#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1 == text2) return text1.size();

        const int   t1s = static_cast<int>(text1.size()),
                    t2s = static_cast<int>(text2.size());

        vector<vector<int>> dp(t2s, vector<int>(t1s));

        dp[0][0] = static_cast<int>(text1[0] == text2[0]);

        for (int i = 1; i < t2s; ++i) {
            dp[i][0] = text1[0] == text2[i] ? 1 : dp[i - 1][0];
        }

        for (int j = 1; j < t1s; ++j) {
            dp[0][j] = text2[0] == text1[j] ? 1 : dp[0][j - 1];
        }

        for (int i = 1; i < t2s; ++i) {
            for (int j = 1; j < t1s; ++j) {
                if (text1[j] == text2[i]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[t2s - 1][t1s - 1];
    }
};