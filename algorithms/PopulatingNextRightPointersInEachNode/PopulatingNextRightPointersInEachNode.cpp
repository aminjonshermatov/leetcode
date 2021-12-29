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

/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return {};

        // (node, level)
        queue<pair<Node*, int>> q;
        q.push({root, 1});

        Node* leftNode = nullptr;
        int level = 0;

        while (!q.empty()) {
            auto [curNode, curLevel] = q.front();
            q.pop();

            if (level == curLevel) {
                leftNode->next = curNode;
            } else {
                if (leftNode != nullptr) leftNode->next = nullptr;
                level = curLevel;
            }
            leftNode = curNode;

            if (curNode->left != nullptr) q.push({curNode->left, level + 1});
            if (curNode->right != nullptr) q.push({curNode->right, level + 1});
        }

        return root;
    }
};