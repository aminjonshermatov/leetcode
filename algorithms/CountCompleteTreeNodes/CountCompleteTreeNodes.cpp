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
    int leftH(TreeNode *node) const {
        if (node == nullptr) return 0;
        return 1 + leftH(node->left);
    }

    int rightH(TreeNode *node) const {
        if (node == nullptr) return 0;
        return 1 + rightH(node->right);
    }
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = leftH(root);
        int rh = rightH(root);

        if (lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};