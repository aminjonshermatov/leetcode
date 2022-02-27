#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int r = static_cast<int>(grid1.size());
        const int c = static_cast<int>(grid1[0].size());

        const function<void(const int, const int)> dfs = [&](const int y, const int x) -> void {
            if (y < 0 or y >= r or x < 0 or x >= c or grid2[y][x] == 0) return;

            grid2[y][x] = 0;
            dfs(y - 1, x);
            dfs(y + 1, x);
            dfs(y, x - 1);
            dfs(y, x + 1);
        };

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid2[i][j] > grid1[i][j]) dfs(i, j);
            }
        }

        int res = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid2[i][j] == 1) {
                    dfs(i, j);
                    ++res;
                }
            }
        }

        return res;
    }
};