#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int r = mat.size(), c = mat[0].size();

    vector<vector<int>> dis(r, vector<int>(c, INT_MAX - 1e5));

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (mat[i][j] == 0)
          dis[i][j] = 0;
        else {
          if (i > 0)
            dis[i][j] = min(dis[i][j], dis[i - 1][j] + 1);
          if (j > 0)
            dis[i][j] = min(dis[i][j], dis[i][j - 1] + 1);
        }
      }
    }

    for (int i = r - 1; i >= 0; --i) {
      for (int j = c - 1; j >= 0; --j) {
        if (i < r - 1)
          dis[i][j] = min(dis[i][j], dis[i + 1][j] + 1);
        if (j < c - 1)
          dis[i][j] = min(dis[i][j], dis[i][j + 1] + 1);
      }
    }

    return dis;
  }
};
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &g) {
    const auto n = int(g.size());
    const auto m = int(g[0].size());
    constexpr int inf = 1e9;
    vector<vector<int>> dp(n, vector<int>(m, inf));
    auto solve = [&]() -> void {
      for (int j = 0; j < m; ++j) {
        if (g[0][j] == 0) {
          dp[0][j] = 0;
        } else if (j > 0) {
          dp[0][j] = min(dp[0][j], dp[0][j - 1] + 1);
        }
      }
      for (int i = 0; i < n; ++i) {
        if (g[i][0] == 0) {
          dp[i][0] = 0;
        } else if (i > 0) {
          dp[i][0] = min(dp[i][0], dp[i - 1][0] + 1);
        }
      }
      for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
          if (g[i][j] == 0) {
            dp[i][j] = 0;
          } else {
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + 1);
          }
        }
      }
    };
    auto rev = [&]() -> void {
      for (int i = 0; i < n; ++i) {
        reverse(dp[i].begin(), dp[i].end());
        reverse(g[i].begin(), g[i].end());
      }
      reverse(g.begin(), g.end());
      reverse(dp.begin(), dp.end());
    };
    solve();
    rev();
    solve();
    rev();
    return dp;
  }
};