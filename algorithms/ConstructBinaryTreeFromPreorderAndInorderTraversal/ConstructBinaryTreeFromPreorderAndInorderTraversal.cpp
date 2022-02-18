#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const function<TreeNode*(const int, const int, const int, const int)> helper = [&](const int pl, const int pr, const int il, const int ir) -> TreeNode* {
            if (pr <= pl or ir <= il) return nullptr;

            const int mid = static_cast<int>(find(inorder.begin(), inorder.end(), preorder[pl]) - inorder.begin()) - il;
            return new TreeNode{preorder[pl], helper(pl + 1, pl + 1 + mid, il, il + mid), helper(pl + 1 + mid, pr, il + mid + 1, ir)};
        };

        const int pn = static_cast<int>(preorder.size());
        const int in = static_cast<int>(inorder.size());

        return helper(0, pn, 0, in);
    }
};