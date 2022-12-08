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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        array<vector<int>, 2> l_values;
        auto dfs = [&](auto self, TreeNode* node, int id) -> void {
            if (node->left == nullptr && node->right == nullptr) {
                l_values[id].emplace_back(node->val);
                return;
            }

            if (node->left != nullptr) self(self, node->left, id);
            if (node->right != nullptr) self(self, node->right, id);
        };

        dfs(dfs, root1, 0);
        dfs(dfs, root2, 1);

        return l_values[0] == l_values[1];
    }
};