#include "bits/stdc++.h"

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;

        queue<Node*> q;
        if (root != nullptr) q.push(root);

        while (!q.empty()) {
            int sz = (int)q.size();
            res.push_back({});
            res.back().reserve(sz);

            while (sz-- > 0) {
                auto v = q.front(); q.pop();

                res.back().emplace_back(v->val);

                for (auto u : v->children) q.push(u);
            }
        }

        return res;
    }
};