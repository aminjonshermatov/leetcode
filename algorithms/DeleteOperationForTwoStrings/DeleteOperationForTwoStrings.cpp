#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int   n = static_cast<int>(word1.size()),
                    m = static_cast<int>(word2.size());

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; ++i) dp[i][0] = i;
        for (int j = 1; j <= m; ++j) dp[0][j] = j;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }

        return dp[n][m];
    }
};

class Solution {
    int dp[501][501];
public:
    int minDistance(string word1, string word2) {
        const int n(word1.size());
        const int m(word2.size());

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) dp[i][j] = -1;
        }

        const function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i >= n) return m - j;
            if (j >= m) return n - i;
            if (dp[i][j] != -1) return dp[i][j];

            return dp[i][j] = word1[i] == word2[j] ? dfs(i + 1, j + 1) : min(dfs(i, j + 1), dfs(i + 1, j)) + 1;
        };

        return dfs(0, 0);
    }
};