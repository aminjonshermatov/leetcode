#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        const int r = static_cast<int>(grid.size());
        const int c = static_cast<int>(grid[0].size());

        const function<void(const int, const int)> dfs = [&](const int y, const int x) -> void {
            if (y < 0 or y >= r or x < 0 or x >= c or grid[y][x] != 0) return;

            grid[y][x] = 1;

            dfs(y - 1, x);
            dfs(y + 1, x);
            dfs(y, x - 1);
            dfs(y, x + 1);
        };

        for (int i = 0; i < r; ++i) {
            if (grid[i][0] == 0) dfs(i, 0);
            if (grid[i][c - 1] == 0) dfs(i, c - 1);
        }

        for (int j = 0; j < c; ++j) {
            if (grid[0][j] == 0) dfs(0, j);
            if (grid[r - 1][j] == 0) dfs(r - 1, j);
        }

        int res = 0;
        for (int i = 1; i < r - 1; ++i) {
            for (int j = 1; j < c - 1; ++j) {
                if (grid[i][j] == 0) {
                    dfs(i, j);
                    ++res;
                }
            }
        }

        return res;
    }
};

class Solution {
    static inline constexpr array<int, 5> dk{1, 0, -1, 0, 1};
  public:
    int closedIsland(vector<vector<int>>& grid) {
        const int n(grid.size());
        const int m(grid[0].size());

        auto is_good = [&](int i, int j) -> bool {
          return clamp(i, 0, n - 1) == i && clamp(j, 0, m - 1) == j;
        };

        auto dfs = [&](auto f, int i, int j) -> bool {
          bool ok = true;
          grid[i][j] = 2;
          for (int k = 0; k < 4; ++k) {
            auto ni = i + dk[k];
            auto nj = j + dk[k + 1];
            if (!is_good(ni, nj)) {
              ok = false;
              continue;
            }
            if (grid[ni][nj] != 0) continue;
            ok &= f(f, ni, nj);
          }
          return ok;
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) continue;
                ans += dfs(dfs, i, j);
            }
        }
        return ans;
    }
};