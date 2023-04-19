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
  int longestZigZag(TreeNode* root) {
    int ans = 0;
    const auto dfs = [&ans](auto f, TreeNode *node, int l, int r) -> void {
      if (node == nullptr) return;
      ans = max(ans, max(l, r));
      f(f, node->left, r + 1, 0);
      f(f, node->right, 0, l + 1);
    };
    dfs(dfs, root, 0, 0);
    return ans;
  }
};