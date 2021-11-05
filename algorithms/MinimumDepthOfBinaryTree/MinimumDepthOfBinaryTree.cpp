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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        deque<TreeNode*> q = {root};
        int curD = 0;

        while (!q.empty()) {
            int n = q.size();

            ++curD;

            while (n--) {
                auto* node = q.front();
                q.pop_front();

                if (node->left != nullptr) q.push_back(node->left);
                if (node->right != nullptr) q.push_back(node->right);
                if (node->left == nullptr && node->right == nullptr) return curD;
            }
        }

        return -1;
    }
};