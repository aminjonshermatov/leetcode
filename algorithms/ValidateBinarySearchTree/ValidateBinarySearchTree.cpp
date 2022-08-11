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
    inline bool helper(int64_t min_, int64_t max_, TreeNode *node) const {
        if (node == nullptr) return true;
        return node->val > min_ && node->val < max_
               && helper(min_, node->val, node->left)
               && helper(node->val, max_, node->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        return helper(INT64_MIN, INT64_MAX, root);
    }
};