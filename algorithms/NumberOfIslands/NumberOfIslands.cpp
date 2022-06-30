#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int n(grid.size());
        const int m(grid[0].size());

        array<int, 5> dk = {1, 0, -1, 0, 1};
        const function<void(int, int)> dfs = [&](int i, int j) {
            grid[i][j] = '0';

            for (int k = 0; k < 4; ++k) {
                int ii = i + dk[k];
                int jj = j + dk[k + 1];

                if (ii >= 0 && ii < n && jj >= 0 && jj < m && grid[ii][jj] != '0') dfs(ii, jj);
            }
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') ++ans, dfs(i, j);
            }
        }

        return ans;
    }
};