#include "bits/stdc++.h"

using namespace std;

class Solution {
  class Dsu {
    int n;
    vector<int> parent, rank;

  public:
    explicit Dsu(int n_) : n(n_) {
      parent.resize(n);
      iota(parent.begin(), parent.end(), 0);
      rank.assign(n, 1);
    }

    auto find(int v) -> int {
      assert(0 <= v && v < n);
      if (parent[v] != v) parent[v] = find(parent[v]);
      return parent[v];
    }

    auto merge(int v, int u) -> int {
      assert(0 <= v && v < n);
      assert(0 <= u && u < n);
      auto pv = find(v);
      auto pu = find(u);
      if (pv == pu) return pv;

      if (rank[pv] < rank[pu]) swap(pv, pu);
      parent[pu] = pv;
      if (rank[pv] == rank[pu]) ++rank[pv];
      return pv;
    }

    auto is_same(int v, int u) -> bool {
      assert(0 <= v && v < n);
      assert(0 <= u && u < n);
      return find(v) == find(u);
    }
  };
  static inline constexpr array<int, 5> dk{1, 0, -1, 0, 1};
public:
  int latestDayToCross(int R, int C, vector<vector<int>>& cells) {
    vector<set<int>> g(R);
    for (auto &e : cells) {
      g[e[0] - 1].emplace(e[1] - 1);
    }
    vector<vector<int>> comp(R, vector<int>(C, -1));
    auto ok = [&](int i, int j) -> bool { return clamp(i, 0, R - 1) == i && clamp(j, 0, C - 1) == j; };
    auto bfs = [&](int I, int J, int c) -> void {
      queue<pair<int, int>> q;
      q.emplace(I, J);
      comp[I][J] = c;
      while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
          auto ni = i + dk[k];
          auto nj = j + dk[k + 1];
          if (!ok(ni, nj) || comp[ni][nj] != -1 || g[ni].count(nj) > 0) continue;
          comp[ni][nj] = c;
          q.emplace(ni, nj);
        }
      }
    };
    for (int i = 0, c = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (comp[i][j] == -1) {
          bfs(i, j, c++);
        }
      }
    }
    Dsu dsu(R * C);
    for (int j = 0; j < C; ++j) {
      dsu.merge(0, j);
      dsu.merge(R * C - 1, C * (R - 1) + j);
    }
    for (int k = int(cells.size()) - 1; k >= 0; --k) {
      auto i = cells[k][0];
      auto j = cells[k][1];
      --i, --j;
      if (i != 0 && i + 1 != R) {
        for (int x = 0; x < 4; ++x) {
          for (int y = 0; y < 4; ++y) {
            auto i1 = i + dk[x];
            auto j1 = j + dk[x + 1];
            if (!ok(i1, j1) || g[i1].count(j1) > 0) continue;
            auto i2 = i + dk[y];
            auto j2 = j + dk[y + 1];
            if (!ok(i2, j2) || g[i2].count(j2) > 0) continue;
            dsu.merge(i1 * C + j1, i2 * C + j2);
            dsu.merge(i1 * C + j1, i * C + j);
            dsu.merge(i * C + j, i2 * C + j2);
          }
        }
      } else {
        for (int x = 0; x < 4; ++x) {
          auto i1 = i + dk[x];
          auto j1 = j + dk[x + 1];
          if (!ok(i1, j1) || g[i1].count(j1) > 0) continue;
          dsu.merge(i1 * C + j1, i * C + j);
        }
      }
      g[i].erase(j);
      if (dsu.find(0) == dsu.find(R * C - 1)) {
        return k;
      }
    }
    return 0;
  }
};