#include "bits/stdc++.h"

using namespace std;

class Solution {
    int dp[101][101];
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        const int n(grid.size());
        const int m(grid[0].size());

        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < m && grid[0][j] != 1; ++j) dp[0][j] = 1;
        for (int i = 0; i < n && grid[i][0] != 1; ++i) dp[i][0] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (grid[i][j] == 1) continue;
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};