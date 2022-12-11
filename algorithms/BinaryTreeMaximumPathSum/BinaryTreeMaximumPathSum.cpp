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
    int maxPathSum(TreeNode* root) {
        int ans = numeric_limits<int>::min();
        auto dfs = [&](auto self, TreeNode *node) -> int {
            if (!node) return 0;
            int l = max(self(self, node->left), 0);
            int r = max(self(self, node->right), 0);

            ans = max(ans, node->val + l + r);
            return node->val + max(l, r);
        };
        dfs(dfs, root);

        return ans;
    }
};