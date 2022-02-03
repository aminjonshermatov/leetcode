#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int   r = static_cast<int>(board.size()),
                    c = static_cast<int>(board[0].size());

        const function<void(const int i, const int j)> check = [&](const int i, const int j) -> void {
            if (i < 0 or i >= r or j < 0 or j >= c or board[i][j] != 'O') return;

            board[i][j] = '#';
            check(i - 1, j);
            check(i, j + 1);
            check(i + 1, j);
            check(i, j - 1);
        };

        for (int i = 0; i < r; ++i) {
            if (board[i][0] == 'O') check(i, 0);
            if (board[i][c - 1] == 'O') check(i, c - 1);
        }

        for (int j = 0; j < c; ++j) {
            if (board[0][j] == 'O') check(0, j);
            if (board[r - 1][j] == 'O') check(r - 1, j);
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};