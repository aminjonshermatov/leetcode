#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int maxSatisfaction(vector<int>& S) {
    const int n(S.size());
    sort(S.begin(), S.end());
    vector<vector<int>> cache(n, vector<int>(n, -1));
    auto dp = [&](auto f, int idx, int t) -> int {
      if (idx >= n) return 0;
      if (~cache[idx][t]) return cache[idx][t];
      return cache[idx][t] = max(f(f, idx + 1, t), f(f, idx + 1, t + 1) + (t + 1) * S[idx]);
    };

    return dp(dp, 0, 0);
  }
};