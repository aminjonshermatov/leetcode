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
    // DFS recursive
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr && targetSum == 0) return true;

        return (root->left != nullptr && this->hasPathSum(root->left, targetSum - root->val))
               || (root->right != nullptr && this->hasPathSum(root->right, targetSum - root->val));
    }

    // DFS iterative
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        stack<pair<TreeNode*, int>> st;

        while (!st.empty()) {
            auto p = st.top();
            st.pop();

            auto* node = p.first;
            int val = p.second;

            if (node->left != nullptr && node->right != nullptr && val == targetSum) return true;

            if (node->left != nullptr) st.push({node->left, node->val + val});
            if (node->right != nullptr) st.push({node->right, node->val + val});
        }

        return false;
    }
};