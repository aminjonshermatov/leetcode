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
class Codec {
    inline static const char DELIMITER = ';';
    inline static const string NULL_NODE = "#";

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;

        const function<void(TreeNode*)> preorder = [&](TreeNode* node) -> void {
            if (node == nullptr) {
                oss << NULL_NODE << DELIMITER;
                return;
            }

            oss << node->val << DELIMITER;
            preorder(node->left);
            preorder(node->right);
        };

        preorder(root);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);

        const function<TreeNode*()> dfs = [&]() -> TreeNode* {
            string cur;
            if (not iss.good()) return nullptr;
            getline(iss, cur, DELIMITER);

            if (cur == NULL_NODE) return nullptr;

            return new TreeNode(stoi(cur), dfs(), dfs());
        };

        return dfs();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));