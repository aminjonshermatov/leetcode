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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        dfs(root, maxD);
        return maxD;
    }

    int dfs(TreeNode* node, int& maxD) {
        if (node == nullptr) return -1;

        int l = dfs(node->left, maxD);
        int r = dfs(node->right, maxD);
        maxD = max(maxD, 2 + l + r);

        return 1 + max(l, r);
    }
};