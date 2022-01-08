#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(),
            c = grid[0].size();

        vector<vector<vector<int>>> cache(r, vector<vector<int>>(c, vector<int>(c, -1)));

        function<int(int, int, int)> dp = [&](int row, int col1, int col2) -> int {
            if (row < 0 || row >= r || col1 < 0 || col1 >= c || col2 < 0 || col2 >= c) return 0;

            int res = cache[row][col1][col2];
            if (res != -1) return res;

            int cur = grid[row][col1];
            if (col1 != col2) cur += grid[row][col2];

            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    res = max(res, cur + dp(row + 1, col1 + i, col2 + j));
                }
            }

            return cache[row][col1][col2] = res;
        };

        return dp(0, 0, c - 1);
    }
};