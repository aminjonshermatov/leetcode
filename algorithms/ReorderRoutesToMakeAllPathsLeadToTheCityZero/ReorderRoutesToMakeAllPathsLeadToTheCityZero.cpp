#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int minReorder(int n, vector<vector<int>> &connections) {
    unordered_map<int, vector<pair<int, int>>> adj;

    for (const auto &con : connections) {
      adj[con[0]].emplace_back(con[1], 1);
      adj[con[1]].emplace_back(con[0], 0);
    }

    vector<bool> visited(n, false);
    const function<int(const int)> dfs = [&](const int root) -> int {
      int res = 0;
      visited[root] = true;

      for (const auto [node, same] : adj[root]) {
        if (visited[node])
          continue;

        res += same + dfs(node);
      }

      return res;
    };

    return dfs(0);
  }
  int minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<int>> g(n);
    vector<set<int>> gg(n);
    for (auto &c : connections) {
      g[c[0]].emplace_back(c[1]);
      gg[c[0]].insert(c[1]);
      g[c[1]].emplace_back(c[0]);
    }

    queue<int> q;
    vector<bool> used(n, false);
    q.emplace(0);
    used[0] = true;
    int ans = 0;
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (auto u : g[v])
        if (!used[u]) {
          ans += gg[v].count(u) > 0;
          used[u] = true;
          q.emplace(u);
        }
    }

    return ans;
  }
};