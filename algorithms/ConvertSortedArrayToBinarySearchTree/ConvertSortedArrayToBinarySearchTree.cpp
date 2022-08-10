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
    vector<int>* nums_;

    TreeNode *helper(int l, int r) const {
        if (l > r) return nullptr;

        auto mid = ((l + r) >> 1) + ((l + r) & 1);
        return new TreeNode{(*nums_)[mid], helper(l, mid - 1), helper(mid + 1, r)};
    };

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        nums_ = &nums;
        return helper(0, static_cast<int>(nums.size()) - 1);
    }
};