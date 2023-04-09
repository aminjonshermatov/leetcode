#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    const int n(colors.size());

    vector<vector<int>> g(n);
    vector<int> in_deg(n, 0);
    for (const auto &e : edges) {
      g[e[0]].emplace_back(e[1]);
      ++in_deg[e[1]];
    }

    vector<int> color(n, 0);
    auto dfs_cycle = [&](auto f, int v) -> bool {
      color[v] = 1;
      for (auto u : g[v]) {
        if (color[u] == 1 || (color[u] == 0 && f(f, u))) {
          return true;
        }
      }
      color[v] = 2;
      return false;
    };
    for (int v = 0; v < n; ++v) {
      if (color[v] == 0 && dfs_cycle(dfs_cycle, v)) {
        return -1;
      }
    }

    queue<int> q;
    for (int v = 0; v < n; ++v) {
      if (in_deg[v] == 0) q.emplace(v);
    }

    vector<array<int, 26>> cnt(n);
    for (int v = 0; v < n; ++v) {
      fill(cnt[v].begin(), cnt[v].end(), 0);
    }
    int ans = 0;
    while (!q.empty()) {
      auto v = q.front(); q.pop();
      cout << v << ' ';
      ++cnt[v][colors[v] - 'a'];
      ans = max(ans, *max_element(cnt[v].begin(), cnt[v].end()));
      for (auto u : g[v]) {
        for (int i = 0; i < 26; ++i) {
          cnt[u][i] = max(cnt[u][i], cnt[v][i]);
        }
        if (--in_deg[u] == 0) {
          q.emplace(u);
        }
      }
    }
    return ans;
  }
};