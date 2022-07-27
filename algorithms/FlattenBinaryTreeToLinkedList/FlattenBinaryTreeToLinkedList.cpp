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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        vector<TreeNode*> nodes;

        while (!st.empty() || root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                nodes.push_back(root);
                root = root->left;
            }

            auto t = st.top(); st.pop();
            root = t->right;
        }

        for (int i = nodes.size() - 2; i >= 0; --i) {
            if (nodes[i] != nullptr) {
                nodes[i]->left = nullptr;
                nodes[i]->right = nodes[i + 1];
            }
        }
    }
};