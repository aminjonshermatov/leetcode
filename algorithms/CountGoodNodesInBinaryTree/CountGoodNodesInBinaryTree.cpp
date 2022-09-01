#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    auto dfs(TreeNode* node, int mx) -> int {
        if (node == nullptr) return 0;

        auto new_mx = max(mx, node->val);
        return (int)(mx <= node->val) + dfs(node->left, new_mx) + dfs(node->right, new_mx);
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};