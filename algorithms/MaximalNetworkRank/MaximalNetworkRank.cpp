#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>>& rs) {
    vector<set<int>> g(n);
    for (auto &r : rs) {
      g[r[0]].emplace(r[1]);
      g[r[1]].emplace(r[0]);
    }
    int ans = 0;
    for (int v = 0; v < n; ++v) {
      for (int u = v + 1; u < n; ++u) {
        ans = max<int>(ans, g[u].size() + g[v].size() - g[v].count(u));
      }
    }
    return ans;
  }
};