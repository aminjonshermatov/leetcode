#include "bits/stdc++.h"

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copies;

        const function<Node*(Node*)> deepCopy = [&](Node *node) -> Node* {
            if (copies.count(node) == 0) {
                if (node == nullptr) copies[node] = node;
                else {
                    copies[node] = new Node(node->val);
                    copies[node]->next = deepCopy(node->next);
                    copies[node]->random = deepCopy(node->random);
                }
            }

            return copies[node];
        };

        return deepCopy(head);
    }
};