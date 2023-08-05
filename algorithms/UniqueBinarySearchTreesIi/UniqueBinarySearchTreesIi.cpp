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
  vector<TreeNode*> generateTrees(int n) {
    auto rec = [&](auto &f, int lo, int hi) -> vector<TreeNode*> {
      vector<TreeNode*> ts;
      if (lo > hi || hi > n) {
        ts.emplace_back(nullptr);
        return ts;
      }
      if (lo == hi) {
        ts.emplace_back(new TreeNode(lo));
        return ts;
      }
      for (int x = lo; x <= hi; ++x) {
        for (auto lhs : f(f, lo, x - 1)) {
          for (auto rhs : f(f, x + 1, hi)) {
            ts.emplace_back(new TreeNode(x, lhs, rhs));
          }
        }
      }
      return ts;
    };
    return rec(rec, 1, n);
  }
};