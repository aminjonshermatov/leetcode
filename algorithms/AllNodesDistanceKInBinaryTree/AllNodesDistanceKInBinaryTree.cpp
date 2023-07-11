#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<vector<int>> g;
    vector<int> vals;
    int n = 0;
    auto dfs = [&](auto &f, TreeNode *node, int p) -> void {
      while (g.size() <= n) {
        g.emplace_back();
      }
      while (vals.size() <= n) {
        vals.emplace_back();
      }

      vals[n] = node->val;
      if (p != -1) {
        g[n].emplace_back(p);
        g[p].emplace_back(n);
      }
      int x = n++;

      for (auto ch : {node->left, node->right}) {
        if (ch == nullptr) continue;
        f(f, ch, x);
      }
    };
    dfs(dfs, root, -1);
    int start = -1;
    for (int v = 0; v < n; ++v) {
      if (vals[v] == target->val) {
        assert(start == -1);
        start = v;
      }
    }
    vector<int> dist(n, -1);
    queue<int> q;
    q.emplace(start);
    dist[start] = 0;
    while (!q.empty()) {
      auto v = q.front(); q.pop();
      for (auto u : g[v]) {
        if (dist[u] == -1) {
          dist[u] = dist[v] + 1;
          q.emplace(u);
        }
      }
    }
    vector<int> ans;
    for (int v = 0; v < n; ++v) {
      if (dist[v] == k) {
        ans.emplace_back(vals[v]);
      }
    }
    return ans;
  }
};