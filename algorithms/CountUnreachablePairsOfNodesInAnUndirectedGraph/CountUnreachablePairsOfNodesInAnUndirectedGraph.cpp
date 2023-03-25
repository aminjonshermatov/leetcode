#include "bits/stdc++.h"

using namespace std;

class Solution {
  using ll = long long;
public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto &e : edges) {
      g[e[0]].emplace_back(e[1]);
      g[e[1]].emplace_back(e[0]);
    }

    vector<bool> used(n, false);
    int cur;
    auto dfs = [&](auto f, int v) -> void {
      ++cur;
      used[v] = true;
      for (auto u : g[v]) if (!used[u]) f(f, u);
    };

    ll ans = 0;
    int pf = 0;
    for (int v = 0; v < n; ++v) {
      if (used[v]) continue;
      cur = 0;
      dfs(dfs, v);
      ans += 1ll * pf * cur;
      pf += cur;
    }

    return ans;
  }
};