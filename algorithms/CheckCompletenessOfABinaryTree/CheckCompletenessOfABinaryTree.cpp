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
  bool isCompleteTree(TreeNode* root) {
    vector<TreeNode*> q;
    q.emplace_back(root);
    int cur_sz_ex = 1;
    while (!q.empty()) {
      auto sz = int(q.size());
      if (sz != cur_sz_ex) return false;
      cur_sz_ex <<= 1;
      vector<TreeNode*> nq;
      bool is_seen_nullptr = false;;
      for (auto node : q) {
        if (node == nullptr) {
          is_seen_nullptr = true;
        } else {
          if (is_seen_nullptr) return false;
          nq.emplace_back(node->left);
          nq.emplace_back(node->right);
        }
      }
      if (all_of(nq.begin(), nq.end(), [](auto node) { return node == nullptr; })) break;
      q.swap(nq);
    }
    return true;
  }
};