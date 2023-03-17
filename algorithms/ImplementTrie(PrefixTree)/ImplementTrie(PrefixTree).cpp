#include "bits/stdc++.h"

using namespace std;

class Trie {
  static inline constexpr int N = 26;
  struct Node {
    int terminated;
    array<Node*, N> go{};
    Node() : terminated(0) {
      fill(go.begin(), go.end(), nullptr);
    }
  };
  Node *root = new Node();
public:
  Trie() = default;

  void insert(string word) {
    auto cur = root;
    for (auto ch : word) {
      if (cur->go[ch - 'a'] == nullptr) cur->go[ch - 'a'] = new Node();
      cur = cur->go[ch - 'a'];
    }
    ++cur->terminated;
  }

  bool search(string word) {
    auto cur = root;
    for (auto ch : word) {
      if (cur->go[ch - 'a'] == nullptr) return false;
      cur = cur->go[ch - 'a'];
    }
    return cur->terminated > 0;
  }

  bool startsWith(string prefix) {
    auto cur = root;
    for (auto ch : prefix) {
      if (cur->go[ch - 'a'] == nullptr) return false;
      cur = cur->go[ch - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */