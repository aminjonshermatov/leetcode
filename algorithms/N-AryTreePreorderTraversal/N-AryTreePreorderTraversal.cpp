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
    vector<int> preorder(Node* root) {
        vector<int> res;

        const function<void(Node*)> preorder = [&](Node *node) -> void {
            if (node == nullptr) return;

            res.push_back(node->val);

            for (const auto child : node->children) preorder(child);
        };

        preorder(root);

        return res;
    }
};