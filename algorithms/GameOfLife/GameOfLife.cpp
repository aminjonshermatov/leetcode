#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int n = static_cast<int>(board.size());
        const int m = static_cast<int>(board[0].size());

        vector<vector<int>> newState(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int live = 0, dead = 0;

                if (i - 1 >= 0) live += static_cast<int>(board[i - 1][j] == 1), dead += static_cast<int>(board[i - 1][j] == 0);
                if (i - 1 >= 0 and j + 1 < m) live += static_cast<int>(board[i - 1][j + 1] == 1), dead += static_cast<int>(board[i - 1][j + 1] == 0);
                if (j + 1 < m) live += static_cast<int>(board[i][j + 1] == 1), dead += static_cast<int>(board[i][j + 1] == 0);
                if (i + 1 < n and j + 1 < m) live += static_cast<int>(board[i + 1][j + 1] == 1), dead += static_cast<int>(board[i + 1][j + 1] == 0);
                if (i + 1 < n) live += static_cast<int>(board[i + 1][j] == 1), dead += static_cast<int>(board[i + 1][j] == 0);
                if (i + 1 < n and j - 1 >= 0) live += static_cast<int>(board[i + 1][j - 1] == 1), dead += static_cast<int>(board[i + 1][j - 1] == 0);
                if (j - 1 >= 0) live += static_cast<int>(board[i][j - 1] == 1), dead += static_cast<int>(board[i][j - 1] == 0);
                if (i - 1 >= 0 and j - 1 >= 0) live += static_cast<int>(board[i - 1][j - 1] == 1), dead += static_cast<int>(board[i - 1][j - 1] == 0);

                if (board[i][j] == 0) {
                    if (live == 3) newState[i][j] = 1;
                } else {
                    if (live < 2 or live > 3) newState[i][j] = 0;
                    if (live == 2 or live == 3) newState[i][j] = 1;
                }
            }
        }

        board = newState;
    }
};