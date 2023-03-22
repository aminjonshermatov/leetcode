#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int minScore(int n, vector<vector<int>>& roads) {
    const int m(roads.size());
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; auto &r : roads) {
      g[r[0] - 1].emplace_back(r[1] - 1, i);
      g[r[1] - 1].emplace_back(r[0] - 1, i);
      ++i;
    }

    vector<bool> used_v(n, false), used_e(m, false);
    auto dfs = [&](auto f, int v) -> void {
      for (auto [u, i] : g[v]) {
        if (!used_v[u]) {
          used_v[u] = true;
          f(f, u);
        }
        used_e[i] = true;
      }
    };

    used_v[0] = true;
    dfs(dfs, 0);
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < m; ++i) if (used_e[i]) ans = min(ans, roads[i][2]);
    return ans;
  }
};