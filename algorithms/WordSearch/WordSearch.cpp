#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> starts;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) starts.push_back({i, j});
            }
        }

        for (const auto [i, j] : starts) {
            if (exist(board, word, i, j, 0)) return true;
        }

        return false;
    }

    bool exist(vector<vector<char>>& b, string& s, int i, int j, int pos) {
        if (pos == s.size()) return true;

        if (i < 0
            || j < 0
            || i >= b.size()
            || j >= b[0].size()
            || b[i][j] != s[pos]
            || b[i][j] == '*') return false;

        char temp = b[i][j];
        b[i][j] = '*';
        bool res = exist(b, s, i + 1, j, pos + 1)
                   || exist(b, s, i - 1, j, pos + 1)
                   || exist(b, s, i, j + 1, pos + 1)
                   || exist(b, s, i, j - 1, pos + 1);
        b[i][j] = temp;
        return res;
    }
};