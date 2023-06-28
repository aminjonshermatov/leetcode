#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < edges.size(); ++i) {
      g[edges[i][0]].emplace_back(edges[i][1], i);
      g[edges[i][1]].emplace_back(edges[i][0], i);
    }
    priority_queue<pair<double, int>> pq;
    vector<double> succ(n, 0);
    succ[start] = 1;
    pq.emplace(1, start);
    while (!pq.empty()) {
      auto [d, v] = pq.top(); pq.pop();
      for (auto [u, e_id] : g[v]) {
        if (d * succProb[e_id] > succ[u]) {
          succ[u] = d * succProb[e_id];
          pq.emplace(succ[u], u);
        }
      }
    }
    return succ[end];
  }
};