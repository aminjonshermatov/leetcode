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
    static inline constexpr int MOD = 1'000'000'007;
public:
    int maxProduct(TreeNode* root) {
        map<TreeNode*, uint64_t> sums;
        auto dfs1 = [&](auto self, TreeNode* node) -> void {
            if (!node) return;

            uint64_t s = node->val;
            if (node->left) self(self, node->left), s += sums[node->left];
            if (node->right) self(self, node->right), s += sums[node->right];
            sums[node] = s;
        };
        dfs1(dfs1, root);

        uint64_t ans = 0;
        auto dfs2 = [&](auto self, TreeNode* node) -> void {
            if (!node) return;

            if (node->left) {
                ans = max(ans, (sums[root] - sums[node->left]) * sums[node->left]);
                self(self, node->left);
            }
            if (node->right) {
                ans = max(ans, (sums[root] - sums[node->right]) * sums[node->right]);
                self(self, node->right);
            }
        };
        dfs2(dfs2, root);

        return ans % MOD;
    }
};