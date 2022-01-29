#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int   r = static_cast<int>(matrix.size()),
                    c = static_cast<int>(matrix[0].size());

        vector<vector<int>> dp(r, vector<int>(c));

        int res = INT_MIN;
        for (int i = 0; i < r; ++i) {
            dp[i][c - 1] = matrix[i][c - 1] - '0';
            res = max(res, dp[i][c - 1]);
        }
        for (int j = 0; j < c; ++j) {
            dp[r - 1][j] = matrix[r - 1][j] - '0';
            res = max(res, dp[r - 1][j]);
        }

        for (int i = r - 2; i >= 0; --i) {
            for (int j = c - 2; j >= 0; --j) {
                dp[i][j] = matrix[i][j] == '0' ? 0 : min(dp[i + 1][j], min(dp[i + 1][j + 1], dp[i][j + 1])) + 1;
                res = max(res, dp[i][j]);
            }
        }

        return res * res;
    }
};