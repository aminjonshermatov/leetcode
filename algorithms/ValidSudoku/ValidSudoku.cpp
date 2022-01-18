#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), square(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                if (rows[i].count(board[i][j]) > 0 or cols[j].count(board[i][j]) > 0 or square[i / 3 * 3 + j / 3].count(board[i][j]) > 0) return false;

                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                square[i / 3 * 3 + j / 3].insert(board[i][j]);
            }
        }

        return true;
    }
};