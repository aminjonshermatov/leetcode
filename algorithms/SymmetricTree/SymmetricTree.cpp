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
    bool isSymmetric(TreeNode* root) {
        if (root->left == nullptr and root->right == nullptr) return true;
        if (root->left == nullptr or root->right == nullptr) return false;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});

        while (not q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [l, r] = q.front();
                q.pop();

                if (l->val != r->val) return false;

                if (static_cast<bool>(l->left) ^ static_cast<bool>(r->right)
                    or static_cast<bool>(l->right) ^ static_cast<bool>(r->left)) return false;

                if (l->left != nullptr and r->right != nullptr) q.push({l->left, r->right});
                if (l->right != nullptr and r->left != nullptr) q.push({l->right, r->left});
            }
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        auto is_ = [](auto f, TreeNode *lhs, TreeNode *rhs) -> bool {
          if ((lhs == nullptr) ^ (rhs == nullptr)) return false;
          if (lhs == nullptr) return true;
          return lhs->val == rhs->val && f(f, lhs->left, rhs->right) && f(f, lhs->right, rhs->left);
        };
        return is_(is_, root->left, root->right);
    }
};