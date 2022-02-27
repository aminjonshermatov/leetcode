#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        const int r = static_cast<int>(grid.size());
        const int c = static_cast<int>(grid[0].size());

        const function<int(const int, const int)> dfs = [&](const int y, const int x) -> int {
            if (y < 0 or y >= r or x < 0 or x >= c or grid[y][x] == 0) return 0;

            grid[y][x] = 0;
            return 1 + dfs(y - 1, x) + dfs(y + 1, x) + dfs(y, x - 1) + dfs(y, x + 1);
        };

        for (int i = 0; i < r; ++i) {
            if (grid[i][0] == 1) dfs(i, 0);
            if (grid[i][c - 1] == 1) dfs(i, c - 1);
        }

        for (int j = 0; j < c; ++j) {
            if (grid[0][j] == 1) dfs(0, j);
            if (grid[r - 1][j] == 1) dfs(r - 1, j);
        }

        int res = 0;
        for (int i = 1; i < r - 1; ++i) {
            for (int j = 1; j < c - 1; ++j) {
                if (grid[i][j] == 1) res += dfs(i, j);
            }
        }

        return res;
    }
};