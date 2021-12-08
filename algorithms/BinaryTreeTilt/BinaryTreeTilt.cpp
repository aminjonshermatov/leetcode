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
    int res = 0;

    int findTilt(TreeNode* root) {
        dfs(root);

        return res;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;

        int l = dfs(node->left),
            r = dfs(node->right);

        res += abs(l - r);

        return l + r + node->val;
    }
};