#include "bits/stdc++.h"

using namespace std;

class Solution {
  static constexpr auto inf = numeric_limits<int>::max();
  static constexpr array<int, 8> dy{-1,-1,-1,+0,+0,+1,+1,+1};
  static constexpr array<int, 8> dx{-1,+0,+1,-1,+1,-1,+0,+1};
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& g) {
    const int n(g.size());
    if (g[0][0] == 1 || g[n - 1][n - 1] == 1) return -1;
    auto ok = [&n](int i, int j) -> bool {
      return clamp(i, 0, n - 1) == i && clamp(j, 0, n - 1) == j;
    };
    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[0][0] = 1;
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
      auto [i, j] = q.front(); q.pop();
      for (int k = 0; k < 8; ++k) {
        auto ni = i + dy[k];
        auto nj = j + dx[k];
        if (!ok(ni, nj) || g[ni][nj] == 1 || ~dist[ni][nj]) continue;
        dist[ni][nj] = dist[i][j] + 1;
        q.emplace(ni, nj);
      }
    }
    return dist[n - 1][n - 1];
  }
};