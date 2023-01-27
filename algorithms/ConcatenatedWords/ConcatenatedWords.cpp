#include "bits/stdc++.h"

using namespace std;

class Solution {
    struct Trie {
        template <size_t N = 26> struct Node {
            char val;
            bool is_end;
            array<Node*, N> child{};

            Node(char val_, bool is_end_) : val(val_), is_end(is_end_) { fill(child.begin(), child.end(), nullptr); }
        };

        Node<> *root;
        Trie() { root = new Node<>('?', false); }

        void add_word(string &s) {
            auto cur = root;
            for (auto ch : s) {
                if (cur->child[ch - 'a'] == nullptr) cur->child[ch - 'a'] = new Node(ch, false);
                cur = cur->child[ch - 'a'];
            }
            cur->is_end = true;
        }

        bool get(string &s) {
            const int n(s.size());
            auto dfs = [&](auto f, Node<> *cur, int id, int cnt) -> bool {
                for (int i = id; i < n; ++i) {
                    if (cur->child[s[i] - 'a'] == nullptr) return false;
                    if (cur->child[s[i] - 'a']->is_end) {
                        if (i + 1 == n) return cnt >= 1;
                        if (f(f, root, i + 1, cnt + 1)) return true;
                    }
                    cur = cur->child[s[i] - 'a'];
                }
                return false;
            };
            return dfs(dfs, root, 0, 0);
        }
    };
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie trie;
        for (auto &s : words) trie.add_word(s);

        vector<string> res;
        for (auto &s : words) if (trie.get(s)) res.emplace_back(s);
        return res;
    }
};