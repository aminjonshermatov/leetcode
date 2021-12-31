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
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = INT_MIN;

        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int, int> {
            vector<int> vals;
            vals.push_back(node->val);

            if (node->left != nullptr) {
                auto [minL, maxL] = dfs(node->left);
                maxDiff = max(maxDiff, max(abs(node->val - minL), abs(node->val - maxL)));
                vals.push_back(minL);
                vals.push_back(maxL);
            }

            if (node->right != nullptr) {
                auto [minR, maxR] = dfs(node->right);
                maxDiff = max(maxDiff, max(abs(node->val - minR), abs(node->val - maxR)));
                vals.push_back(minR);
                vals.push_back(maxR);
            }

            int minEl = *min_element(vals.begin(), vals.end());
            int maxEl = *max_element(vals.begin(), vals.end());
            maxDiff = max(maxDiff, max(abs(node->val - minEl), abs(node->val - maxEl)));

            return {minEl, maxEl};
        };

        dfs(root);

        return maxDiff;
    }
};