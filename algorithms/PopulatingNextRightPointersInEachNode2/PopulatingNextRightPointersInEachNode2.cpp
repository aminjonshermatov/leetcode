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
        if (root == nullptr) return root;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = (int)q.size();
            Node *cur = nullptr;

            while (sz--) {
                auto it = q.front(); q.pop();

                if (cur != nullptr) {
                    cur->next = it;
                    cur = it;
                }
                else cur = it;

                if (it->left != nullptr) q.push(it->left);
                if (it->right != nullptr) q.push(it->right);
            }
        }

        return root;
    }
};