#include "bits/stdc++.h"

using namespace std;

class Solution {
  using ll = long long;
public:
  ll minimumFuelCost(vector<vector<int>>& roads, int s) {
    const int n(roads.size() + 1);
    vector<vector<int>> g(n);
    for (const auto &e : roads) {
      g[e[0]].emplace_back(e[1]);
      g[e[1]].emplace_back(e[0]);
    }

    vector<int> sz(n, 0);
    auto dfs = [&](auto f, int v, int p) -> void {
      ++sz[v];
      for (auto u : g[v]) if (u != p) f(f, u, v), sz[v] += sz[u];
    };

    dfs(dfs, 0, -1);
    ll ans = 0;
    for (int i = 1; i < n; ++i) ans += 1ll * (sz[i] + s - 1) / s;

    return ans;
  }
};