#include "bits/stdc++.h"

using namespace std;

class Solution {
  using i64 = int64_t;
  static constexpr i64 mod = 1e9 + 7;
  static constexpr i64 X = 100057;
  inline i64 add(i64 a, i64 b) { return (a + b) % mod; }
  inline i64 mul(i64 a, i64 b) { return (a * b) % mod; }
public:
  int equalPairs(vector<vector<int>>& grid) {
    const int n(grid.size());
    vector<i64> rows(n), cols(n);
    for (int i = 0; i < n; ++i) {
      i64 cur = 0;
      for (int j = 0; j < n; ++j) {
        cur = add(mul(cur, X), grid[i][j]);
      }
      rows[i] = cur;
    }
    for (int j = 0; j < n; ++j) {
      i64 cur = 0;
      for (int i = 0; i < n; ++i) {
        cur = add(mul(cur, X), grid[i][j]);
      }
      cols[j] = cur;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans += rows[i] == cols[j];
      }
    }
    return ans;
  }
};