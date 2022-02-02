#include "bits/stdc++.h"

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        queue<Node*> q;

        Node* curNode = nullptr;
        q.push(root);
        while (not q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto node{q.front()}; q.pop();
                if (curNode == nullptr) curNode = node;
                else {
                    curNode->next = node;
                    curNode = curNode->next;
                }

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            curNode = nullptr;
        }

        return root;
    }
};