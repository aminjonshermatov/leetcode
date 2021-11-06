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
    // recursive BFS
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;

        stack<pair<TreeNode*, TreeNode*>> st;

        st.push({root1, root2});

        while (!st.empty()) {
            auto [n1, n2] = st.top();
            st.pop();

            if (n2 == nullptr) continue;

            n1->val += n2->val;

            if (n1->left == nullptr) {
                n1->left = n2->left;
            } else {
                st.push({n1->left, n2->left});
            }

            if (n1->right == nullptr) {
                n1->right = n2->right;
            } else {
                st.push({n1->right, n2->right});
            }
        }

        return root1;
    }

    // iterative DFS
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};