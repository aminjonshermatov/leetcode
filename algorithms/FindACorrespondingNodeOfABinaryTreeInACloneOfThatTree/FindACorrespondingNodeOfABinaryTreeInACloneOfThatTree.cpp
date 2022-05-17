#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(cloned);

        while (!q.empty()) {
            auto t = q.front(); q.pop();

            if (t->val == target->val) return t;

            if (t->left != nullptr) q.push(t->left);
            if (t->right != nullptr) q.push(t->right);
        }

        return nullptr;
    }
};