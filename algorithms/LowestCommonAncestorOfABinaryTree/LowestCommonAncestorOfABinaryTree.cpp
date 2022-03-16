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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        const function<list<TreeNode*>(TreeNode*)> getPath = [&](TreeNode *node) -> list<TreeNode*> {
            list<TreeNode*> l;
            unordered_map<TreeNode*, int> w;

            auto cur{root};

            while (cur != nullptr or not l.empty()) {
                while (cur != nullptr) {
                    l.push_back(cur);
                    if (cur == node) return l;
                    cur = cur->left;
                }

                ++w[l.back()];
                cur = l.back()->right;
                if (w[l.back()] > 1) l.pop_back();
            }

            return l;
        };

        auto pL{getPath(p)};
        auto qL{getPath(q)};

        auto res{root};
        while (not pL.empty() and not qL.empty() and pL.front() == qL.front()) {
            res = pL.front();
            pL.pop_front();
            qL.pop_front();
        }

        return res;
    }
};