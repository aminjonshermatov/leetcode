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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy = new TreeNode(-1);
        auto cur{dummy};
        stack<TreeNode*> st;

        while (not st.empty() or root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            root = st.top(); st.pop();
            root->left = nullptr;
            cur->right = root;
            cur = cur->right;
            root = root->right;
        }

        return dummy->right;
    }
};