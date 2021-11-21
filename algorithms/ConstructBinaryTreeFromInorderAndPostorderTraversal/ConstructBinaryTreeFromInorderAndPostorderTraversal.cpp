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

template <typename T>
ostream& operator<<(ostream& out, const vector<T> v) {
    out << '[';

    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) out << ", ";
        out << v[i];
    }

    return out << ']';
}

class Solution {
public:
    TreeNode* buildTree(vector<int> inorder, vector<int> postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;

        int inLen = static_cast<int>(inorder.size()),
                postLen = static_cast<int>(postorder.size());

        int leftChildCount = static_cast<int>(find(inorder.begin(), inorder.end(), postorder[postLen - 1]) - inorder.begin()),
                rightChildCount = inLen - leftChildCount - 1;

        auto *root = new TreeNode(postorder[postLen - 1]);

        if (leftChildCount > 0) {
            vector<int> leftInorder, leftPostorder;

            // left subTree
            for (int i = 0; i < leftChildCount; ++i) leftInorder.push_back(inorder[i]);
            for (int i = 0; i < leftChildCount; ++i) leftPostorder.push_back(postorder[i]);

            root->left = buildTree(leftInorder, leftPostorder);
        }

        if (rightChildCount > 0) {
            vector<int> rightInorder, rightPostorder;

            // right subTree
            for (int i = 0; i < rightChildCount; ++i) rightInorder.push_back(inorder[leftChildCount + i + 1]);
            for (int i = 0; i < rightChildCount; ++i) rightPostorder.push_back(postorder[leftChildCount + i]);

            root->right = buildTree(rightInorder, rightPostorder);
        }

        return root;
    }
};