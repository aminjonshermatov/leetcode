#include "bits/stdc++.h"

using namespace std;

class Solution {
  static inline constexpr auto inf = numeric_limits<int>::max();
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<set<int>> r(n);
    for (auto &e : redEdges) r[e[0]].insert(e[1]);
    vector<set<int>> b(n);
    for (auto &e : blueEdges) b[e[0]].insert(e[1]);

    array<vector<int>, 2> dist;
    for (int i = 0; i < 2; ++i) {
      dist[i].assign(n, inf);
      dist[i][0] = 0;
    }
    queue<pair<int, int>> q; // (v, type) => type == 1 if red else blue
    for (auto v : r[0]) q.emplace(v, 1), dist[0][v] = 1;
    for (auto v : b[0]) q.emplace(v, 2), dist[1][v] = 1;

    while (!q.empty()) {
      auto [u, type] = q.front(); q.pop();
      for (auto v : (type == 1 ? b : r)[u]) {
        if (dist[type - 1][u] + 1 < dist[(3 ^ type) - 1][v]) {
          q.emplace(v, 3 ^ type);
          dist[(3 ^ type) - 1][v] = dist[type - 1][u] + 1;
        }
      }
    }
    vector<int> ans(n, -1);
    for (int u = 0; u < n; ++u) {
      auto mn = min(dist[0][u], dist[1][u]);
      if (mn != inf) ans[u] = mn;
    }
    ans[0] = 0;
    return ans;
  }
};