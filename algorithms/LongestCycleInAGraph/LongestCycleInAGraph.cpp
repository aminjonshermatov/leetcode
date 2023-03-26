#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int longestCycle(vector<int>& edges) {
    const int n(edges.size());
    int cs, ce;
    vector<int> color(n, 0);
    auto dfs = [&](auto f, int v) -> bool {
      color[v] = 1;
      auto u = edges[v];
      if (u != -1 && color[u] != 2) {
        if (color[u] == 0) {
          if (f(f, u)) return true;
        } else if (color[u] == 1) {
          cs = u;
          ce = v;
        }
      }
      color[v] = 2;
      return false;
    };

    int ans = -1;
    for (int v = 0; v < n; ++v) {
      if (color[v] == 0) {
        cs = ce = -1;
        dfs(dfs, v);
        if (cs != -1) {
          int len = 1;
          for (int cur = cs; cur != ce; cur = edges[cur]) ++len;
          ans = max(ans, len);
        }
      }
    }
    return ans;
  }
};