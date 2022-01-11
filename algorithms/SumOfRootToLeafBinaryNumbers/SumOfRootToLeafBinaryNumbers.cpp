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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int curSum) -> void {
            if (node->left == nullptr && node->right == nullptr) {
                sum += curSum * 2 + node->val;
                return;
            }

            if (node->left != nullptr) dfs(node->left, curSum * 2 + node->val);
            if (node->right != nullptr) dfs(node->right, curSum * 2 + node->val);
        };

        dfs(root, 0);

        return sum;
    }
};