#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool PredictTheWinner(vector<int>& as) {
    const int n(as.size());
    vector<vector<array<array<int, 2>, 2>>> cache(n, vector<array<array<int, 2>, 2>>(n));
    vector<vector<array<bool, 2>>> seen(n, vector<array<bool, 2>>(n, {false, false}));
    auto dp = [&](auto &f, int l, int r, bool which) -> array<int, 2> {
      if (l > r) return {0, 0};
      if (seen[l][r][which]) return cache[l][r][which];
      auto lhs = f(f, l + 1, r, !which);
      lhs[which] += as[l];
      auto rhs = f(f, l, r - 1, !which);
      rhs[which] += as[r];
      seen[l][r][which] = true;
      return cache[l][r][which] = lhs[which] > rhs[which] ? lhs : rhs;
    };
    auto ans = dp(dp, 0, n - 1, 0);
    return ans[0] >= ans[1];
  }
};