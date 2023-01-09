#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        auto dfs = [&](auto f, TreeNode* node) -> void {
            if (node == nullptr) return;
            res.emplace_back(node->val);
            f(f, node->left);
            f(f, node->right);
        };
        dfs(dfs, root);
        return res;
    }
};