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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode{val, root, nullptr};

        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int d) {
            if (node == nullptr) return;

            if (d == 1) {
                node->left = new TreeNode{val, node->left, nullptr};
                node->right = new TreeNode{val, nullptr, node->right};
                return;
            }

            dfs(node->left, d - 1);
            dfs(node->right, d - 1);
        };

        dfs(root, depth - 1);
        return root;
    }
};