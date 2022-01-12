#include "bits/stdc++.h"

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<int, Node*> cache;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        if (cache.count(node->val) == 0) {
            cache[node->val] = new Node(node->val);
            for (const auto &n : node->neighbors) {
                cache[node->val]->neighbors.push_back(cloneGraph(n));
            }
        }

        return cache[node->val];
    }
};