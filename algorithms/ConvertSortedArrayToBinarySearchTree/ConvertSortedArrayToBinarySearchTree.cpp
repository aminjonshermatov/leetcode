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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        const function<TreeNode*(const int, const int)> helper = [&](const int l, const int r) -> TreeNode* {
            if (r <= l) return nullptr;

            const int mid = l + ((r - l) >> 1);
            return new TreeNode{nums[mid], helper(l, mid), helper(mid + 1, r)};
        };

        return helper(0, n);
    }
};