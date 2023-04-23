#include "bits/stdc++.h"

using namespace std;

class Solution {
  using ll = long long;
  static constexpr ll mod = 1e9 + 7;
public:
  int numberOfArrays(string s, int k) {
    const int n(s.size());
    vector<ll> cache(n, -1);
    const auto dp = [&](auto f, int idx) -> ll {
      if (idx >= n) return 1;
      if (~cache[idx]) return cache[idx];
      ll loc = 0, cur = 0;
      for (int i = idx; i < n && cur * 10 + (s[i] - '0') <= k; ++i) {
        if (i + 1 >= n || s[i + 1] != '0') {
          loc += f(f, i + 1);
          loc %= mod;
        }
        cur = cur * 10 + (s[i] - '0');
      }
      return cache[idx] = loc;
    };
    return dp(dp, 0);
  }
};