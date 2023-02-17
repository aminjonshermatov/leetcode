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
  static inline constexpr auto  inf = numeric_limits<int>::max();
  static inline constexpr auto ninf = numeric_limits<int>::min();
public:
  int minDiffInBST(TreeNode* root) {
    vector<int> vals;
    auto dfs = [&](auto f, TreeNode *node) -> void {
      vals.emplace_back(node->val);
      for (auto x : {node->left, node->right}) {
        if (x == nullptr) continue;
        f(f, x);
      }
    };
    dfs(dfs, root);
    sort(vals.begin(), vals.end());
    int ans = inf;
    const int n(vals.size());
    for (int i = 1; i < n; ++i) ans = min(ans, vals[i] - vals[i - 1]);
    return ans;
  }
};