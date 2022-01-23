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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        function<void(TreeNode*)> dfs = [&](TreeNode *node) -> void {
            if (node == nullptr) return;

            dfs(node->left);
            dfs(node->right);
            res.push_back(node->val);
        };

        dfs(root);

        return res;
    }
};