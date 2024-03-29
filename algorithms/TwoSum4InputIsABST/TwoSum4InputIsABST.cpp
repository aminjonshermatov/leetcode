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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> nums;

        function<bool(TreeNode*)> dfs = [&](TreeNode* node) -> bool {
            if (node == nullptr) return false;

            if (nums.count(k - node->val) > 0) return true;
            nums.insert(node->val);

            return dfs(node->left) or dfs(node->right);
        };

        return dfs(root);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> ss;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto v = q.front(); q.pop();

            if (ss.count(k - v->val) > 0) return true;

            ss.insert(v->val);
            for (auto u : {v->left, v->right}) {
                if (u != nullptr) q.push(u);
            }
        }

        return false;
    }
};