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

    bool isValidSudoku(vector<vector<char>>& board) {
        uint16_t rows[9] = {0,}, cols[9] = {0,}, sqr[9] = {0,};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (!isdigit(static_cast<unsigned char>(board[i][j]))) continue;

                int cur = board[i][j] - '1';
                if ((rows[i] >> cur) & 1) return false;
                rows[i] |= 1 << cur;

                if ((cols[j] >> cur) & 1) return false;
                cols[j] |= 1 << cur;

                int idx = i / 3 * 3 + j / 3;
                if ((sqr[idx] >> cur) & 1) return false;
                sqr[idx] |= 1 << cur;
            }
        }

        return true;
    }
};
