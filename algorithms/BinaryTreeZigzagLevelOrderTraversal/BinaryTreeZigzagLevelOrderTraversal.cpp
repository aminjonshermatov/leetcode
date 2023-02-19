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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    vector<vector<int>> res;

    queue<TreeNode*> q;
    q.push(root);
    bool is_rev = false;
    while (!q.empty()) {
      vector<int> cur;

      int sz(q.size());
      while (sz--) {
        auto t = q.front(); q.pop();
        cur.emplace_back(t->val);
        if (t->left != nullptr) q.emplace(t->left);
        if (t->right != nullptr) q.emplace(t->right);
      }

      if (is_rev) reverse(cur.begin(), cur.end());
      res.emplace_back(cur);
      is_rev ^= true;
    }

    return res;
  }
};