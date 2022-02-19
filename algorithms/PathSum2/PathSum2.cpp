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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        list<int> cur;

        const function<void(TreeNode*, int target)> dfs = [&](TreeNode* node, int target) -> void {
            if (node == nullptr) return;

            cur.push_back(node->val);
            target -= node->val;

            if (node->left == nullptr and node->right == nullptr) {
                if (target == 0) res.push_back({cur.begin(), cur.end()});
            } else {
                dfs(node->left, target);
                dfs(node->right, target);
            }

            cur.pop_back();
        };

        dfs(root, targetSum);

        return res;
    }
};