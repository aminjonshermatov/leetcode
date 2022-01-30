#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; i + j < n; ++j) {
                if (s[j] == s[i + j]) dp[j][i + j] = 2 + dp[j + 1][i + j - 1];
                else dp[j][i + j] = max(dp[j + 1][i + j], dp[j][i + j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};