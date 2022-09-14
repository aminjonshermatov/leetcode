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
    int pseudoPalindromicPaths (TreeNode* root) {
        array<int, 9> freq;
        fill(freq.begin(), freq.end(), 0);

        function<int(TreeNode*)> dfs;
        dfs = [&freq, &dfs](TreeNode* node) -> int {
            ++freq[node->val - 1];
            int res = 0;
            if (node->left == nullptr && node->right == nullptr) {
                bool any_odd = false, ok = true;;
                for (const auto num : freq) {
                    if (num & 1) {
                        if (any_odd) ok = false;
                        else any_odd = true;
                    }
                }

                if (ok) res = 1;
            }

            if (node->left != nullptr) res += dfs(node->left);
            if (node->right != nullptr) res += dfs(node->right);

            --freq[node->val - 1];
            return res;
        };

        return dfs(root);
    }
};