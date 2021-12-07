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
    bool isValidBST(TreeNode* root) {
        return inorder(root, static_cast<long long>(INT_MIN) - 1, static_cast<long long>(INT_MAX) + 1);
    }

    bool inorder(TreeNode* root, long long min, long long max) {
        if (root == nullptr) return true;

        return min < root->val
               && max > root->val
               && inorder(root->left, min, root->val) && inorder(root->right, root->val, max);
    }
};