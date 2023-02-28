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
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    map<string, pair<bool, TreeNode*>> cache;
    auto dfs = [&](auto f, TreeNode *node) -> string {
      if (node == nullptr) return "#";
      string path = to_string(node->val);
      path.push_back(':');
      path.append(f(f, node->left));
      path += ",";
      path.append(f(f, node->right));
      auto it = cache.find(path);
      if (it != cache.end()) it->second.first = true;
      else cache.emplace(path, pair(false, node));
      return path;
    };

    dfs(dfs, root);
    vector<TreeNode*> res;
    for (auto &[_, kv] : cache) if (kv.first) res.emplace_back(kv.second);
    return  res;
  }
};