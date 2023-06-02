#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int maximumDetonation(vector<vector<int>>& B) {
    const int n(B.size());

    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        auto x = B[i][0] - B[j][0];
        auto y = B[i][1] - B[j][1];
        auto d = 1ll * x * x + 1ll * y * y;
        if (1ll * B[i][2] * B[i][2] >= d) {
          g[i].emplace_back(j);
        }
      }
    }

    auto bfs = [&](int S) -> int {
      vector<int> used(n, 0);
      used[S] = 1;
      queue<int> q;
      q.emplace(S);
      while (!q.empty()) {
        auto v = q.front(); q.pop();
        for (auto u : g[v]) {
          if (!used[u]) {
            used[u] = 1;
            q.emplace(u);
          }
        }
      }
      return accumulate(used.begin(), used.end(), 0);
    };

    int ans = 0;
    for (int v = 0; v < n; ++v) {
      ans = max(ans, bfs(v));
    }
    return ans;
  }
};