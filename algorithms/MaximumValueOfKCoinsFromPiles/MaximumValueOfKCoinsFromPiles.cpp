#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    const int n(piles.size());

    vector<vector<int>> cache(n, vector<int>(k + 1, -1));
    const auto dp = [&](auto &f, int i, int kk) -> int {
      if (i >= n || kk < 1) return 0;
      if (~cache[i][kk]) return cache[i][kk];
      int ans = f(f, i + 1, kk), sum = 0;
      for (int j = 0; j < piles[i].size() && j < kk; ++j) {
        sum += piles[i][j];
        ans = max(ans, sum + f(f, i + 1, kk - j - 1));
      }
      return cache[i][kk] = ans;
    };

    return dp(dp, 0, k);
  }
};