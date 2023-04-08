/*
// Definition for a Node.
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
*/

class Solution {
  unordered_map<int, Node*> cache;
public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return node;
    if (cache.count(node->val) == 0) {
      auto nw = cache[node->val] = new Node(node->val);
      nw->neighbors.reserve(node->neighbors.size());
      for (auto n : node->neighbors) {
        nw->neighbors.emplace_back(cloneGraph(n));
      }
    }
    return cache[node->val];
  }
};