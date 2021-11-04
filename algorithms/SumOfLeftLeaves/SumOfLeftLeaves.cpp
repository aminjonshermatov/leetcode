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
        return this->sumOfLeftLeaves(root, false);
    }

    int sumOfLeftLeaves(TreeNode* root, bool isLeft) {
        if (root->left == nullptr && root->right == nullptr) {
            return isLeft ? root->val : 0;
        } else {
            return (root->left == nullptr ? 0 : this->sumOfLeftLeaves(root->left, true))
                   + (root->right == nullptr ? 0 : this->sumOfLeftLeaves(root->right, false));
        }
    }
};