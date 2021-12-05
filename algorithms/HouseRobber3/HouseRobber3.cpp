#include "bits/stdc++.h"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        auto [with, without] = dfs(root);
        return max(with, without);
    }

    pair<int, int> dfs(TreeNode *root) {
        if (root == nullptr) return {0, 0};

        auto [lWith, lWithout] = dfs(root->left);
        auto [rWith, rWithout] = dfs(root->right);

        int with = root->val + lWithout + rWithout;
        int without = max(lWith, lWithout) + max(rWith, rWithout);

        return {with, without};
    }
};