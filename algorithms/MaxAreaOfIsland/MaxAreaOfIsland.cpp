#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int n(grid.size());
        const int m(grid[0].size());

        array<int, 5> dk = { -1, 0, 1, 0, -1 };

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;

            int acc = 1;
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) acc += dfs(i + dk[k], j + dk[k + 1]);

            return acc;
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) ans = max(ans, dfs(i, j));
            }
        }


        return ans;
    }
};
