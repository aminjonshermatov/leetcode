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
  int getMinimumDifference(TreeNode* root) {
    int ans = 1e9, prv = -1;
    auto dfs = [&](auto &f, TreeNode *node) -> void {
      if (node == nullptr) return;
      f(f, node->left);
      if (~prv) ans = min(ans, node->val - prv);
      prv = node->val;
      f(f, node->right);
    };
    dfs(dfs, root);
    return ans;
  }
};