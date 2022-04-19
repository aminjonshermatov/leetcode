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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> arr;

        const function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) return;
            dfs(node->left);
            arr.push_back(node);
            dfs(node->right);
        };

        dfs(root);

        const int n = static_cast<int>(arr.size());
        int l = 0;
        while (l < n - 1) {
            if (arr[l]->val > arr[l + 1]->val) break;
            ++l;
        }

        int r = n - 1;
        while (r > 0) {
            if (arr[r]->val < arr[r - 1]->val) break;
            --r;
        }

        swap(arr[l]->val, arr[r]->val);
    }
};