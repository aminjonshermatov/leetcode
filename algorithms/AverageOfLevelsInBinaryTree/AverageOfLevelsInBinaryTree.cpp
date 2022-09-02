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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = (int)q.size(), cnt = 0;
            double curS = 0.;

            while (sz-- > 0) {
                auto it = q.front(); q.pop();

                curS += it->val;
                ++cnt;
                if (it->left != nullptr) q.push(it->left);
                if (it->right != nullptr) q.push(it->right);
            }
            res.push_back(curS / cnt);
        }

        return res;
    }
};