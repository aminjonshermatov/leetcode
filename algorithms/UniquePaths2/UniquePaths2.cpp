#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        const int r = grid.size();
        const int c = grid[0].size();

        if (grid[0][0] == 1 or grid[r - 1][c - 1] == 1) return 0;

        vector<vector<int>> dp(r, vector<int>(c));
        dp[0][0] = 1;

        for (int i = 1; i < r; ++i) dp[i][0] = grid[i][0] == 1 ? 0 : dp[i - 1][0];
        for (int j = 1; j < c; ++j) dp[0][j] = grid[0][j] == 1 ? 0 : dp[0][j - 1];

        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (grid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[r - 1][c - 1];
    }
};