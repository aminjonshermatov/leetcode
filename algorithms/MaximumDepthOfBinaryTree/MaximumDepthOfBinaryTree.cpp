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
    // recursive DFS
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // iterative DFS
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        stack<pair<TreeNode*, int>> st;
        int maxD = 0, curD = 0;

        while (root != nullptr || !st.empty()) {
            while (root != nullptr) {
                st.push({root, ++curD});
                root = root->left;
            }

            auto [temp, depth] = st.top();
            st.pop();
            curD = depth;
            maxD = max(maxD, depth);
            root = temp->right;
        }

        return maxD;
    }
};