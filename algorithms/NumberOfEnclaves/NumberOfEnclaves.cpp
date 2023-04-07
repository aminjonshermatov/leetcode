#include "bits/stdc++.h"

using namespace std;

class Solution {
  static inline constexpr array<int, 5> dk{1, 0, -1, 0, 1};
public:
  int numEnclaves(vector<vector<int>>& grid) {
    const int n(grid.size());
    const int m(grid[0].size());

    auto is_good = [&](int i, int j) -> bool {
      return clamp(i, 0, n - 1) == i && clamp(j, 0, m - 1) == j;
    };

    auto dfs = [&](auto f, int i, int j) -> void {
      grid[i][j] = 2;
      for (int k = 0; k < 4; ++k) {
        auto ni = i + dk[k];
        auto nj = j + dk[k + 1];
        if (!is_good(ni, nj) || grid[ni][nj] != 1) continue;
        f(f, ni, nj);
      }
    };

    for (int i = 0; i < n; ++i) {
      for (auto j : {0, m - 1}) {
        if (grid[i][j] == 1) dfs(dfs, i, j);
      }
    }
    for (int j = 0; j < m; ++j) {
      for (auto i : {0, n - 1}) {
        if (grid[i][j] == 1) dfs(dfs, i, j);
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans += grid[i][j] == 1;
      }
    }
    return ans;
  }
};