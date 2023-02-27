#include "bits/stdc++.h"

using namespace std;

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
  using pii = pair<int, int>;
public:
  Node* construct(vector<vector<int>>& grid) {
    const int n(grid.size());
    auto lg = [](int x) { return 31 - __builtin_clz(x); };
    const int _lg = lg(n);
    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(_lg + 1, false)));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j][0] = true;
      }
    }
    array<int, 2> cnt{};
    for (int k = 1; k <= _lg; ++k) {
      int delta = 1 << (k - 1);
      for (int i = 0; i < n; i += 1 << k) {
        for (int j = 0; j < n; j += 1 << k) {
          auto same = dp[i][j][k - 1] && dp[i + delta][j][k - 1] && dp[i][j + delta][k - 1] && dp[i + delta][j + delta][k - 1];
          cnt[0] = cnt[1] = 0;
          ++cnt[grid[i][j]];
          ++cnt[grid[i + delta][j]];
          ++cnt[grid[i][j + delta]];
          ++cnt[grid[i + delta][j + delta]];
          dp[i][j][k] = same && (cnt[0] == 4 || cnt[1] == 4);
        }
      }
    }

    auto rec = [&](auto f, pii lt, pii rb) -> Node* {
      auto mid = (rb.first - lt.first) / 2;
      if (mid == 0 || dp[lt.second][lt.first][lg(mid) + 1]) {
        return new Node(grid[lt.second][lt.first], true);
      }
      auto ret = new Node(true, false);

      ret->topLeft = f(f, lt, pii(lt.first + mid, lt.second + mid));
      ret->topRight = f(f, pii(lt.first + mid, lt.second), pii(rb.first, rb.second - mid));
      ret->bottomLeft = f(f, pii(lt.first, lt.second + mid), pii(rb.first - mid, rb.second));
      ret->bottomRight = f(f, pii(lt.first + mid, lt.second + mid), rb);
      return ret;
    };
    return rec(rec, pii(0, 0), pii(n, n));
  }
};