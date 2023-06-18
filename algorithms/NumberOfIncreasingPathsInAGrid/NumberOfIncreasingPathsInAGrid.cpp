#include "bits/stdc++.h"

using namespace std;

class Solution {
  static constexpr int mod = 1e9 + 7;
  inline int add(int a, int b) { return (a + b) % mod; }
  static constexpr array<int, 5> dk{1, 0, -1, 0, 1};
public:
  int countPaths(vector<vector<int>>& g) {
    const int n(g.size());
    const int m(g[0].size());

    auto ok = [&n, &m](int i, int j) -> bool {
      return clamp(i, 0, n - 1) == i && clamp(j, 0, m - 1) == j;
    };

    vector<vector<int>> cache(n, vector<int>(m, -1));
    auto dfs = [&](auto &f, int i, int j) -> int {
      if (~cache[i][j]) return cache[i][j];
      int loc = 1;
      for (int k = 0; k < 4; ++k) {
        auto ni = i + dk[k];
        auto nj = j + dk[k + 1];
        if (!ok(ni, nj) || g[ni][nj] <= g[i][j]) continue;
        loc = add(loc, f(f, ni, nj));
      }
      return cache[i][j] = loc;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans = add(ans, dfs(dfs, i, j));
      }
    }
    return ans;
  }
};