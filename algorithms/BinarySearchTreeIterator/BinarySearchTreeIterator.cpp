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
class BSTIterator {
public:
    list<int> vals;

    BSTIterator(TreeNode* root) {
        stack<TreeNode*> st;

        while (not st.empty() or root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            root = st.top(); st.pop();
            vals.push_back(root->val);
            root = root->right;
        }
    }

    int next() {
        auto res{vals.front()};
        vals.pop_front();
        return res;
    }

    bool hasNext() {
        return not vals.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */