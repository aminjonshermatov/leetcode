#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    const int r = static_cast<int>(isConnected.size()),
              c = static_cast<int>(isConnected[0].size());

    queue<int> q;
    int count = 0;

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (isConnected[i][j] == 1) {
          if (q.empty())
            ++count;
          isConnected[i][j] = 0;
          q.push(j);
        }
      }

      while (not q.empty()) {
        auto y = q.front();
        q.pop();

        for (int j = 0; j < c; ++j) {
          if (isConnected[y][j] == 1) {
            q.push(j);
            isConnected[y][j] = 0;
          }
        }
      }
    }

    return count;
  }

  class Solution {
  public:
    int findCircleNum(vector<vector<int>> &adj) {
      const int n(adj.size());
      vector<int> p(n), rank(n, 0);
      iota(p.begin(), p.end(), 0);
      int comp = n;
      auto find = [&](auto &f, int v) -> int {
        if (v != p[v])
          v = f(f, p[v]);
        return p[v];
      };
      auto unite = [&](int u, int v) -> void {
        auto pu = find(find, u);
        auto pv = find(find, v);
        if (pu == pv)
          return;
        --comp;
        if (rank[pu] < rank[pv])
          swap(pu, pv);
        p[pv] = pu;
        rank[pu] += rank[pu] == rank[pv];
      };

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (adj[i][j])
            unite(i, j);
        }
      }
      return comp;
    }
  };
};