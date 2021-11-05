#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        deque<TreeNode*> q1, q2;

        if (p == nullptr && q == nullptr) return true;

        if ((p == nullptr) ^ (q == nullptr)) return false;

        q1.push_back(p);
        q2.push_back(q);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size(), n2 = q2.size();

            if (n1 != n2) return false;

            while (n1--) {
                auto *node1 = q1.front(), *node2 = q2.front();
                q1.pop_front();
                q2.pop_front();

                bool l1 = node1->left != nullptr;
                bool r1 = node1->right != nullptr;
                bool l2 = node2->left != nullptr;
                bool r2 = node2->right != nullptr;

                if (
                        node1->val != node2->val
                        || (l1 ^ l2)
                        || (r1 ^ r2)
                        ) return false;

                if (l1) q1.push_back(node1->left);
                if (r1) q1.push_back(node1->right);
                if (l2) q2.push_back(node2->left);
                if (r2) q2.push_back(node2->right);
            }
        }

        return q1.empty() && q2.empty();
    }
};
