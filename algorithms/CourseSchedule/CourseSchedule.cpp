#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool canFinish(int n, vector<vector<int>>& es) {
    vector<vector<int>> g(n);
    vector<int> indeg(n, 0);
    for (auto &e : es) {
      g[e[1]].emplace_back(e[0]);
      ++indeg[e[0]];
    }

    queue<int> q;
    vector<bool> used(n, false);
    for (int v = 0; v < n; ++v) {
      if (indeg[v] == 0) {
        q.emplace(v);
        used[v] = true;
      }
    }

    while (!q.empty()) {
      auto v = q.front(); q.pop();
      for (auto u : g[v]) {
        if (--indeg[u] == 0) {
          used[u] = true;
          q.emplace(u);
        }
      }
    }
    // return all_of(used.begin(), used.end(), identity());
    return all_of(used.begin(), used.end(), [](auto x) { return x; });
  }
};