#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);

        TreeNode *res = root, *cur = root;

        while (cur != nullptr) {
            res = cur;
            if (cur->val >= p->val && cur->val <= q->val) {
                break;
            } else if (cur->val <= p->val && cur->val <= q->val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }

        return res;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        if (root == nullptr || (root->val >= p->val && root->val <= q->val)) return root;
        if (root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};