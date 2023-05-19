#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool isBipartite(vector<vector<int>>& g) {
    const int n(g.size());
    vector<int> color(n, 0);
    auto dfs = [&](auto f, int v, int c) -> bool {
      color[v] = c;
      for (auto u : g[v]) {
        if ((color[u] == 0 && !f(f, u, 3 ^ c)) || color[u] != (3 ^ c)) {
          return false;
        }
      }
      return true;
    };

    for (int v = 0; v < n; ++v) {
      if (color[v] != 0) continue;
      if (!dfs(dfs, v, 1)) return false;
    }
    return true;
  }
};