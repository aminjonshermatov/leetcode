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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) -> void {
            if (node == nullptr) return;

            res.push_back(node->val);
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);

        return res;
    }
};