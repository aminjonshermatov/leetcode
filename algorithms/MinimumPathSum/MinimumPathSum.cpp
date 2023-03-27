#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    const int r = static_cast<int>(grid.size()),
              c = static_cast<int>(grid[0].size());

    vector<vector<int>> dp(r, vector<int>(c));

    dp[0][0] = grid[0][0];

    for (int i = 1; i < r; ++i)
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < c; ++j)
      dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < r; ++i) {
      for (int j = 1; j < c; ++j) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[r - 1][c - 1];
  }
  int minPathSum(vector<vector<int>> &grid) {
    const int n(grid.size());
    const int m(grid[0].size());

    vector<int> dp(m);
    for (int j = 0; j < m; ++j) {
      dp[j] = grid[0][j];
      if (j > 0)
        dp[j] += dp[j - 1];
    }
    for (int i = 1; i < n; ++i) {
      vector<int> ndp(m);
      for (int j = 0; j < m; ++j) {
        auto mn = dp[j];
        if (j > 0)
          mn = min(mn, ndp[j - 1]);
        ndp[j] = mn + grid[i][j];
      }
      dp.swap(ndp);
    }
    return dp[m - 1];
  }
};