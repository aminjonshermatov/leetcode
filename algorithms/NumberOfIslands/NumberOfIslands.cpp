#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(),
            c = grid[0].size();

        function<void(int, int)> dfs = [&](int y, int x) -> void {
            grid[y][x] = '0';

            if (y - 1 >= 0 && grid[y - 1][x] == '1') dfs(y - 1, x);
            if (y + 1 < r && grid[y + 1][x] == '1') dfs(y + 1, x);
            if (x - 1 >= 0 && grid[y][x - 1] == '1') dfs(y, x - 1);
            if (x + 1 < c && grid[y][x + 1] == '1') dfs(y, x + 1);
        };

        int count = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    ++count;
                }
            }
        }

        return count;
    }
};