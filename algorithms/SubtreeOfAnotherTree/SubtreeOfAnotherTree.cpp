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
    bool isSameNode(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) return true;
        if (a != nullptr && b != nullptr)
            return a->val == b->val && isSameNode(a->left, b->left) && isSameNode(a->right, b->right);

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        deque<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            auto* temp = q.front();
            q.pop_front();

            if (isSameNode(temp, subRoot)) return true;

            if (temp->left != nullptr) q.push_back(temp->left);
            if (temp->right != nullptr) q.push_back(temp->right);
        }

        return false;
    }
};