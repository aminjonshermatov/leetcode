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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        auto* inverted = new TreeNode(root->val);

        deque<pair<TreeNode*, TreeNode*>> q;
        q.emplace_back(root, inverted);

        while (!q.empty()) {
            auto p = q.front();
            auto *r = p.first, *i = p.second;

            q.pop_front();

            i->left = r->right == nullptr ? nullptr : new TreeNode(r->right->val);
            i->right = r->left == nullptr ? nullptr : new TreeNode(r->left->val);

            if (i->left != nullptr) q.emplace_back(r->right, i->left);
            if (i->right != nullptr) q.emplace_back(r->left, i->right);
        }

        return inverted;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        auto l{root->left};
        auto r{root->right};

        root->right = invertTree(l);
        root->left = invertTree(r);

        return root;
    }
};