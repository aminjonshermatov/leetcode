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
  int maxLevelSum(TreeNode* root) {
    int ans = -1, mx = -1e9 - 10;
    queue<TreeNode*> q;
    q.emplace(root);
    for (int level = 1; !q.empty(); ++level) {
      int s = 0;
      for (int sz(q.size()); sz--;) {
        auto node = q.front(); q.pop();
        s += node->val;
        for (auto ch : {node->left, node->right}) {
          if (ch == nullptr) continue;
          q.emplace(ch);
        }
      }
      if (s > mx) {
        mx = s;
        ans = level;
      }
    }
    assert(ans != -1);
    return ans;
  }
};