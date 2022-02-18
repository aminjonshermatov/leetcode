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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        bool needToReverse = false;
        q.push(root);

        while (not q.empty()) {
            int sz = static_cast<int>(q.size());
            vector<int> cur;

            while (sz--) {
                auto curNode{q.front()}; q.pop();
                cur.push_back(curNode->val);

                if (curNode->left != nullptr) q.push(curNode->left);
                if (curNode->right != nullptr) q.push(curNode->right);
            }

            if (needToReverse) reverse(cur.begin(), cur.end());

            res.emplace_back(cur);
            needToReverse = not needToReverse;
        }

        return res;
    }
};