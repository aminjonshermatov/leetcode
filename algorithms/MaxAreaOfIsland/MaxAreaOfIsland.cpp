#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        function<int(int, int)> dfs = [&dfs, &grid](int x, int y) -> int {
            if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size() || grid[y][x] == 0) return 0;

            grid[y][x] = 0;
            return 1 + dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1);
        };

        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) continue;
                maxArea = max(maxArea, dfs(j, i));
            }
        }

        return maxArea;
    }
};