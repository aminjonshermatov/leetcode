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
  int sumNumbers(TreeNode* root) {
    int ans = 0;
    auto dfs = [&](auto f, TreeNode *node, int p_val) -> void {
      if (node == nullptr) return;
      int local = p_val * 10 + node->val;
      if (node->left == nullptr && node->right == nullptr) {
        ans += local;
        return;
      }
      f(f, node->left, local);
      f(f, node->right, local);
    };
    dfs(dfs, root, 0);
    return ans;
  }
};