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
    int sumOfLeftLeaves(TreeNode* root) {
        const function<int(TreeNode*, bool)> dfs = [&](TreeNode *node, bool isLeft) -> int {
            if (node == nullptr) return 0;
            if (node->left == nullptr and node->right == nullptr and isLeft) return node->val;
            return dfs(node->left, true) + dfs(node->right, false);
        };

        return dfs(root, false);
    }
};