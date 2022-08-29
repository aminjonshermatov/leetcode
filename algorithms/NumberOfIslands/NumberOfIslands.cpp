#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int N(grid.size());
        const int M(grid[0].size());

        array<int, 5> dk = {1,0,-1,0,1};
        function<void(int, int)> dfs = [&](int i, int j) {
            grid[i][j] = '0';

            for (int k = 0; k < 4; ++k) {
                int ii = i + dk[k];
                int jj = j + dk[k + 1];
                if (ii < 0 || ii >= N || jj < 0 || jj >= M || grid[ii][jj] != '1') continue;
                dfs(ii, jj);
            }
        };

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == '1') dfs(i, j), ++ans;
            }
        }

        return ans;
    }
};