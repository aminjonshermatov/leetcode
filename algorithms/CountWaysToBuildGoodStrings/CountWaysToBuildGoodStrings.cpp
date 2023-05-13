#include "bits/stdc++.h"

using namespace std;

class Solution {
  using i64 = ::int64_t;
  static constexpr i64 mod = 1e9 + 7;
  inline i64 add(i64 a, i64 b) { return (a + b) % mod; }
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<i64> dp(high + 1);
    dp[0] = 1;
    for (int len = 1; len <= high; ++len) {
      for (auto x : {zero, one}) {
        if (len >= x) {
          dp[len] = add(dp[len], dp[len - x]);
        }
      }
    }
    i64 ans = 0;
    for (int len = low; len <= high; ++len) {
      ans = add(ans, dp[len]);
    }
    return ans;
  }
};