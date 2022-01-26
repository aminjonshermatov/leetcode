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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> st1, st2;

        while (root1 != nullptr or root2 != nullptr or not st1.empty() or not st2.empty()) {
            while (root1 != nullptr) {
                st1.push(root1);
                root1 = root1->left;
            }

            while (root2 != nullptr) {
                st2.push(root2);
                root2 = root2->left;
            }

            if (st2.empty() || (not st1.empty() and st1.top()->val <= st2.top()->val)) {
                auto top{st1.top()};

                res.push_back(top->val);
                st1.pop();
                root1 = top->right;
            } else {
                auto top{st2.top()};

                res.push_back(top->val);
                st2.pop();
                root2 = top->right;
            }
        }

        return res;
    }
};