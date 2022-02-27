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
    int widthOfBinaryTree(TreeNode* root) {
        list<pair<TreeNode*, const uint64_t>> q;
        q.push_back({root, 0ull});

        int res = 0;
        while (not q.empty()) {
            auto sz{static_cast<int>(q.size())};

            auto [_, lIdx] = q.front();
            auto [__, rIdx] = q.back();
            res = max<int>(res, rIdx - lIdx + 1ull);

            while (sz-- > 0) {
                auto [cur, idx] = q.front(); q.pop_front();

                if (cur->left != nullptr) q.push_back({cur->left, 2 * idx});
                if (cur->right != nullptr) q.push_back({cur->right, 2 * idx + 1});
            }
        }

        return res;
    }
};