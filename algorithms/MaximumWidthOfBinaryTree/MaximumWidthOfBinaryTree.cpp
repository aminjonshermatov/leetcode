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
    queue<pair<TreeNode*, uint64_t>> q;
    q.emplace(root, 0);
    uint64_t ans = 0;
    while (!q.empty()) {
      uint64_t mn = 0, mx = 0;
      bool used_mn = false, used_mx = false;
      for (int sz(q.size()); sz > 0; --sz) {
        auto [v, lev] = q.front(); q.pop();
        if (!used_mn || mn > lev) used_mn = true, mn = lev;
        if (!used_mx || mx < lev) used_mx = true, mx = lev;
        if (v->left != nullptr) q.emplace(v->left, 2 * lev);
        if (v->right != nullptr) q.emplace(v->right, 2 * lev + 1);
      }
      ans = max(ans, mx - mn + 1);
    }
    return ans;
  }
};