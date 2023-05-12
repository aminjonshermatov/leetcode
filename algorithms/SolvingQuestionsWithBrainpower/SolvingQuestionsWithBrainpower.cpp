#include "bits/stdc++.h"

using namespace std;

class Solution {
  using i64 = long long;
public:
  i64 mostPoints(vector<vector<int>>& qs) {
    const int n(qs.size());
    vector<i64> cache(n, -1);
    auto dp = [&](auto &f, int i) -> i64 {
      if (i >= n) return 0;
      if (~cache[i]) return cache[i];
      return cache[i] = max(qs[i][0] + f(f, i + qs[i][1] + 1), f(f, i + 1));
    };
    return dp(dp, 0);
  }
};