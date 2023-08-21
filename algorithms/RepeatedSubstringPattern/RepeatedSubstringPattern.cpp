#include "bits/stdc++.h"

using namespace std;

class Solution {
  using i64 = int64_t;
  static constexpr i64 P = 97, mod = 1000001269ll;
  inline i64 add(i64 a, i64 b) { return (a + b) % mod; }
  inline i64 mul(i64 a, i64 b) { return (a * b) % mod; }
  inline i64 sub(i64 a, i64 b) { return (a + mod - b) % mod; }
public:
  bool repeatedSubstringPattern(string s) {
    const auto n = int(s.size());
    vector<i64> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
      pw[i] = mul(pw[i - 1], P);
    }
    vector<i64> hs(n);
    hs[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; ++i) {
      hs[i] = add(mul(hs[i - 1], P), s[i] - 'a' + 1);
    }
    auto get = [&](int l, int r) -> i64 {
      assert(0 <= l && l <= r && r < n);
      return sub(hs[r], mul(l > 0 ? hs[l - 1] : 0, pw[r - l + 1]));
    };
    for (int len = 1; len < n; ++len) {
      bool ok = true;
      for (int i = 0; i < n; i += len) {
        ok &= get(0, len - 1) == get(i, min(i + len - 1, n - 1));
      }
      if (ok) {
        return true;
      }
    }
    return false;
  }
};