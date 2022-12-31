#include "bits/stdc++.h"

using namespace std;

class Solution {
    static inline constexpr array<int, 5> dk{1, 0, -1, 0, 1};
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        const int n(grid.size());
        const int m(grid[0].size());

        auto is_safe = [&](int y, int x) -> bool { return y >= 0 && y < n && x >= 0 && x < m; };

        pair<int, int> S, E;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) S = make_pair(i, j), grid[i][j] = -1;
                else if (grid[i][j] == 2) E = make_pair(i, j), grid[i][j] = 0;
            }
        }

        int ans = 0;
        auto dfs = [&](auto self, int y, int x) -> void {
            if (y == E.first && x == E.second) {
                bool ok = true;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) ok &= grid[i][j] != 0;
                }
                ans += ok;
                return;
            }

            for (int k = 0; k < 4; ++k) {
                int yy = y + dk[k];
                int xx = x + dk[k + 1];

                if (is_safe(yy, xx) && grid[yy][xx] != -1) {
                    grid[yy][xx] = -1;
                    self(self, yy, xx);
                    grid[yy][xx] = 0;
                }
            }
        };

        dfs(dfs, S.first, S.second);
        return ans;
    }
};