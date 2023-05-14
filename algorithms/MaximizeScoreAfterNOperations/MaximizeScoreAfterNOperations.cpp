#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int maxScore(vector<int>& nums) {
    const int n(nums.size());
    vector<int> cache(1 << n, -1);
    auto rec = [&](auto &f, int mask) -> int {
      auto cnt = __builtin_popcount(mask);
      assert(cnt % 2 == 0);
      if (cnt == n) return 0;
      if (~cache[mask]) return cache[mask];
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        if (mask >> i & 1) continue;
        for (int j = 0; j < n; ++j) {
          if (mask >> j & 1 || i == j) continue;
          ans = max(ans, (cnt / 2 + 1) * __gcd(nums[i], nums[j]) + f(f, mask | (1 << i) | (1 << j)));
        }
      }
      return cache[mask] = ans;
    };
    return rec(rec, 0);
  }
};