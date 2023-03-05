#include "bits/stdc++.h"

using namespace std;

class Solution {
  static inline constexpr auto inf = numeric_limits<int>::max();
public:
  int minJumps(vector<int>& arr) {
    const int n(arr.size());
    map<int, vector<int>> sameVals;
    for (int i = 0; i < n; ++i) sameVals[arr[i]].emplace_back(i);

    queue<int> q;
    q.emplace(0);
    vector<int> dist(n, inf);
    dist[0] = 0;
    while (!q.empty()) {
      auto v = q.front(); q.pop();
      assert(dist[v] != inf);
      for (auto u : {v - 1, v + 1}) {
        if (clamp(u, 0, n - 1) != u || dist[u] <= dist[v] + 1) continue;
        dist[u] = dist[v] + 1;
        q.emplace(u);
      }
      for (auto u : sameVals[arr[v]]) if (u != v && dist[u] > dist[v] + 1) {
          dist[u] = dist[v] + 1;
          q.emplace(u);
        }
      sameVals[arr[v]].clear();
    }
    assert(dist[n - 1] != inf);
    return dist[n - 1];
  }
};