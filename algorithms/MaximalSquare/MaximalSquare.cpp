#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = static_cast<int>(matrix.size()),
                n = static_cast<int>(matrix[0].size());

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            dp[m - 1][i] = matrix[m - 1][i] - '0';
            res = max(res, dp[m - 1][i]);
        }
        for (int i = 0; i < m; ++i) {
            dp[i][n - 1] = matrix[i][n - 1] - '0';
            res = max(res, dp[i][n - 1]);
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = matrix[i][j] == '0' ? 0 : min(dp[i + 1][j], min(dp[i + 1][j + 1], dp[i][j + 1])) + 1;
                res = max(res, dp[i][j]);
            }
        }

        return res * res;
    }
};