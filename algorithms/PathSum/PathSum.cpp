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
        function<bool(TreeNode*, int)> dfs = [&](TreeNode *node, int s) -> bool {
            if (node == nullptr) return false;
            if (node->left == nullptr && node->right == nullptr) return s == node->val;

            return dfs(node->left, s - node->val) || dfs(node->right, s - node->val);
        };

        return dfs(root, targetSum);
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