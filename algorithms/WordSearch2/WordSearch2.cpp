#include "bits/stdc++.h"

using namespace std;

class Solution {
    struct TrieNode {
        bool is_tail;
        int idx;
        array<TrieNode*, 26> child;
        TrieNode() : is_tail(false), idx(-1) { fill(child.begin(), child.end(), nullptr); }
    };

    TrieNode* root;

    auto add_word(const string &w, int idx) {
        auto cur = root;
        for (auto ch : w) {
            if (cur->child[ch - 'a'] == nullptr) cur->child[ch - 'a'] = new TrieNode{};
            cur = cur->child[ch - 'a'];
        }
        cur->is_tail = true;
        cur->idx = idx;
    }

    static inline constexpr array<int, 5> dk = {1, 0, -1, 0, 1};

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode{};
        for (int i = 0; i < (int)words.size(); ++i) add_word(words[i], i);

        vector<string> res;
        auto is_safe = [&](int i, int j) { return i >= 0 && i < (int)board.size() && j >= 0 && j < (int)board[0].size(); };
        auto dfs = [&](auto &self, int i, int j, TrieNode* node) -> void {
            if (node == nullptr) return;
            if (node->is_tail) {
                res.emplace_back(words[node->idx]);
                node->is_tail = false;
                node->idx = -1;
            }

            auto p = board[i][j];
            board[i][j] = '#';

            for (int k = 0; k < 4; ++k) {
                int ii = i + dk[k], jj = j + dk[k + 1];
                if (is_safe(ii, jj) && board[ii][jj] != '#') {
                    self(self, ii, jj, node->child[board[ii][jj] - 'a']);
                }
            }

            board[i][j] = p;
        };

        for (int i = 0; i < (int)board.size(); ++i) {
            for (int j = 0; j < (int)board[0].size(); ++j) {
                dfs(dfs, i, j, root->child[board[i][j] - 'a']);
            }
        }

        return res;
    }
};