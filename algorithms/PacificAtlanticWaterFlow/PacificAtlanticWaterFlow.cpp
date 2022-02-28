#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int r = static_cast<int>(heights.size());
        const int c = static_cast<int>(heights[0].size());

        using Board = vector<vector<bool>>;

        const function<void(Board&, const int, const int)> dfs = [&](Board &board, const int y, const int x) -> void {
            if (board[y][x]) return;

            board[y][x] = true;

            if (y - 1 >= 0 and heights[y - 1][x] >= heights[y][x]) dfs(board, y - 1, x);
            if (y + 1 < r and heights[y + 1][x] >= heights[y][x]) dfs(board, y + 1, x);
            if (x - 1 >= 0 and heights[y][x - 1] >= heights[y][x]) dfs(board, y, x - 1);
            if (x + 1 < c and heights[y][x + 1] >= heights[y][x]) dfs(board, y, x + 1);
        };

        Board atlantic(r, vector<bool>(c, false)), pacific(r, vector<bool>(c, false));

        for (int i = 0; i < r; ++i) {
            dfs(pacific, i, 0);
            dfs(atlantic, i, c - 1);
        }

        for (int j = 0; j < c; ++j) {
            dfs(pacific, 0, j);
            dfs(atlantic, r - 1, j);
        }

        vector<vector<int>> res;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (atlantic[i][j] and pacific[i][j]) res.push_back({i, j});
            }
        }

        return res;
    }
};