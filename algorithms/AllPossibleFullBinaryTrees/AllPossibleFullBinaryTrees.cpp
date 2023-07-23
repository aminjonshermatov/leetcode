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
  vector<TreeNode*> allPossibleFBT(int n) {
    auto rec = [&](auto &rec, int left) -> vector<TreeNode*> {
      vector<TreeNode*> nodes;
      if (left == 1) {
        nodes.emplace_back(new TreeNode(0));
        return nodes;
      }
      assert(left > 1);
      for (int lhs = 1, rhs = left - 2; rhs > 0; ++lhs, --rhs) {
        auto l = rec(rec, lhs);
        auto r = rec(rec, rhs);
        for (int i = 0; i < l.size(); ++i) {
          for (int j = 0; j < r.size(); ++j) {
            nodes.emplace_back(new TreeNode(0, l[i], r[j]));
          }
        }
      }
      return nodes;
    };
    return rec(rec, n);
  }
};