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
    vector<double> averageOfLevels(TreeNode* root) {
        deque<TreeNode*> q;

        q.push_back(root);
        vector<double> res;

        while (!q.empty()) {
            int n = q.size(), i = n;
            double sum = 0;

            while (i) {
                --i;
                auto* node = q.front();
                q.pop_front();

                sum += node->val;

                if (node->left != nullptr) {
                    q.push_back(node->left);
                }

                if (node->right != nullptr) {
                    q.push_back(node->right);
                }
            }

            res.push_back(sum / n);
        }

        return res;
    }
};