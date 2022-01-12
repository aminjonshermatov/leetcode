#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(),
            c = heights[0].size();

        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));

        function<void(vector<vector<bool>>&, int, int)> dfs = [&](vector<vector<bool>> &board, int y, int x) -> void {
            if (board[y][x]) return;

            board[y][x] = true;

            // top
            if (y - 1 >= 0 && heights[y - 1][x] >= heights[y][x]) dfs(board, y - 1, x);

            // right
            if (x + 1 < c && heights[y][x + 1] >= heights[y][x]) dfs(board, y, x + 1);

            // down
            if (y + 1 < r && heights[y + 1][x] >= heights[y][x]) dfs(board, y + 1, x);

            // right
            if (x - 1 >= 0 && heights[y][x - 1] >= heights[y][x]) dfs(board, y, x - 1);
        };

        for (int i = 0; i < r; ++i) {
            dfs(pacific, i, 0);
            dfs(atlantic, i, c - 1);
        }

        for (int i = 0; i < c; ++i) {
            dfs(pacific, 0, i);
            dfs(atlantic, r - 1, i);
        }

        vector<vector<int>> res;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (atlantic[i][j] && pacific[i][j]) res.push_back({i, j});
            }
        }

        return res;
    }
};