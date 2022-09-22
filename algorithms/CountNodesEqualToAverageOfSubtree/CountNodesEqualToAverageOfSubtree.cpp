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
    int averageOfSubtree(TreeNode* root) {
        int res = 0;

        function<pair<int, int>(TreeNode*)> dfs;
        dfs = [&res, &dfs](TreeNode* node) -> pair<int, int> {
            int sum = node->val, cnt = 1;

            for (const auto child : {node->left, node->right}) {
                if (child == nullptr) continue;
                auto [ss, cc] = dfs(child);
                sum += ss;
                cnt += cc;
            }

            res += node->val == sum / cnt;
            return {sum, cnt};
        };

        dfs(root);
        return res;
    }
};