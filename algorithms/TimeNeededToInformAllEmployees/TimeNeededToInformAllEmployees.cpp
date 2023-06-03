#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {
    vector<vector<int>> g(n);
    int root = -1;
    for (int i = 0; i < n; ++i) {
      if (~manager[i]) {
        g[manager[i]].emplace_back(i);
      } else {
        root = i;
      }
    }
    vector<int> dist(n, -1);
    queue<int> q;
    q.emplace(root);
    dist[root] = informTime[root];
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (auto u : g[v]) {
        assert(dist[u] == -1);
        dist[u] = dist[v] + informTime[u];
        q.emplace(u);
      }
    }
    return *max_element(dist.begin(), dist.end());
  }
  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {
    unordered_map<int, unordered_set<int>> adj;

    for (int i = 0; i < n; ++i)
      adj[manager[i]].insert(i);

    const function<int(const int)> dfs = [&](const int root) -> int {
      if (adj[root].empty())
        return 0;

      int temp = 0;
      for (const auto emp : adj[root])
        temp = max(temp, dfs(emp));

      return temp + informTime[root];
    };

    return dfs(headID);
  }
};