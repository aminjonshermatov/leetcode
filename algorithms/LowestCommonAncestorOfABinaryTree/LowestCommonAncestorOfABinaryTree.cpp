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
    inline auto dfs(TreeNode* node, TreeNode* cur, list<TreeNode*>& l) -> bool {
        l.push_back(node);

        if (node == cur) return true;
        if (node->left != nullptr and dfs(node->left, cur, l)) return true;
        if (node->right != nullptr and dfs(node->right, cur, l)) return true;
        l.pop_back();
        return false;
    }

    inline auto print_l(list<TreeNode*> l) -> void {
        while (not l.empty()) {
            cout << l.front()->val << ':';
            l.pop_front();
        }
        cout << '\n';
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto curQ{root};
        list<TreeNode*> lP, lQ;

        dfs(root, p, lP);
        dfs(root, q, lQ);
        // print_l(lP);
        // print_l(lQ);

        assert(lP.front() == lQ.front());

        TreeNode* res = nullptr;

        while (not lP.empty() and not lQ.empty() and lP.front() == lQ.front()) {
            res = lP.front();
            lP.pop_front();
            lQ.pop_front();
        }

        return res;
    }
};