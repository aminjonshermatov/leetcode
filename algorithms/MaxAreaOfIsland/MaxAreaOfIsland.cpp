#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int r = static_cast<int>(grid.size());
        const int c = static_cast<int>(grid[0].size());

        const function<int(const int, const int)> dfs = [&](const int x, const int y) -> int {
            if (y < 0 || y >= r || x < 0 || x >= c || grid[y][x] == 0) return 0;

            grid[y][x] = 0;
            return 1 + dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1);
        };

        int maxArea = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 0) continue;
                maxArea = max(maxArea, dfs(j, i));
            }
        }

        return maxArea;
    }
};