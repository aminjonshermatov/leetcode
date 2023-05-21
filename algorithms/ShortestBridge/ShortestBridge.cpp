#include "bits/stdc++.h"

using namespace std;

class Solution {
  static inline constexpr array<int, 5> dk{1, 0, -1, 0, 1};
public:
  int shortestBridge(vector<vector<int>>& g) {
    const int n(g.size());
    const int m(g[0].size());

    auto ok = [&n, &m](int i, int j) -> bool {
      return clamp(i, 0, n - 1) == i && clamp(j, 0, m - 1) == j;
    };

    queue<tuple<int, int, int>> q;
    auto dfs = [&](auto &f, int i, int j) -> void {
      g[i][j] = -1;
      q.emplace(i, j, 0);
      for (int k = 0; k < 4; ++k) {
        auto ni = i + dk[k];
        auto nj = j + dk[k + 1];
        if (!ok(ni, nj) || g[ni][nj] != 1) continue;
        f(f, ni, nj);
      }
    };

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (g[i][j] == 1) {
          dfs(dfs, i, j);
          goto bfs;
        }
      }
    }
  bfs:
    while (!q.empty()) {
      auto [i, j, d] = q.front(); q.pop();
      for (int k = 0; k < 4; ++k) {
        auto ni = i + dk[k];
        auto nj = j + dk[k + 1];
        if (!ok(ni, nj) || g[ni][nj] == -1) continue;
        if (g[ni][nj] == 1) return d;
        g[ni][nj] = -1;
        q.emplace(ni, nj, d + 1);
      }
    }
    assert(false);
  }
};