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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> L;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int level = 0;
        while (!q.empty()) {
            int sz = (int)q.size();

            while (sz-- > 0) {
                auto [node, idx] = q.front(); q.pop();

                L[idx].emplace_back(level, node->val);
                if (node->left != nullptr) q.push({node->left, idx - 1});
                if (node->right != nullptr) q.push({node->right, idx + 1});
            }
            ++level;
        }

        vector<vector<int>> res;
        res.reserve(L.size());

        for (auto &[_, arr] : L) {
            sort(arr.begin(), arr.end());
            res.push_back({});
            for (auto [_, val] : arr) res.back().emplace_back(val);
        }

        return res;
    }
};