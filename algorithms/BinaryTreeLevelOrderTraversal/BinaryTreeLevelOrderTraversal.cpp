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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> res;

        queue<TreeNode*> q;
        int level = 0;
        q.push(root);

        while (not q.empty()) {
            int sz = q.size();
            vector<int> temp;

            while (sz--) {
                auto cur{q.front()};
                q.pop();

                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);

                temp.push_back(cur->val);
            }

            res.push_back(temp);
            ++level;
        }

        return res;
    }
};