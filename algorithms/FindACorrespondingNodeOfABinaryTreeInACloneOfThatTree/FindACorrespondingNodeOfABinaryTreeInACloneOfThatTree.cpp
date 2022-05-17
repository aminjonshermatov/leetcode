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
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push(make_pair(original, cloned));

        while (!q.empty()) {
            auto [o, c] = q.front(); q.pop();

            if (o == target) return c;

            if (o->left != nullptr) q.push(make_pair(o->left, c->left));
            if (o->right != nullptr) q.push(make_pair(o->right, c->right));
        }

        return nullptr;
    }
};