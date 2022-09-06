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
    pair<TreeNode*, bool> prune(TreeNode* node) {
        if (node == nullptr) return {node, false};

        auto [ln, lh] = prune(node->left);
        auto [rn, rh] = prune(node->right);

        if (!lh) node->left = nullptr;
        if (!rh) node->right = nullptr;

        return {node, lh || rh || node->val == 1};
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        auto [n, b] = prune(root);
        return b ? n : nullptr;
    }
};