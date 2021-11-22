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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *found = root, *foundP = nullptr;

        while (found != nullptr) {
            if (found->val > key) {
                foundP = found;
                found = found->left;
            } else if (found->val < key) {
                foundP = found;
                found = found->right;
            } else {
                break;
            }
        }

        if (found != nullptr) {
            auto *rightMinChild = findMinNode(found->right);

            if (rightMinChild != nullptr) {
                rightMinChild->left = found->left;

                if (foundP != nullptr) {
                    if (found == foundP->left) {
                        foundP->left = found->right;
                    } else {
                        foundP->right = found->right;
                    }
                } else {
                    root = found->right;
                }
            } else {
                if (foundP != nullptr) {
                    if (found == foundP->left) {
                        foundP->left = found->left;
                    } else {
                        foundP->right = found->left;
                    }
                } else {
                    root = found->left;
                }
            }
        }

        return root;
    }

    TreeNode* findMinNode(TreeNode* node) {
        if (node == nullptr) return node;
        if (node->left != nullptr) return findMinNode(node->left);
        else return node;
    }
};