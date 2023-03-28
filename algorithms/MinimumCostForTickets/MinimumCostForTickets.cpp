#include "bits/stdc++.h"

using namespace std;

class Solution {
  static inline constexpr array<int, 3> durations{1, 7, 30};
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    const int n(days.size());
    vector<int> cache(n, -1);
    auto dp = [&](auto f, int idx) -> int {
      if (idx >= n) return 0;
      if (~cache[idx]) return cache[idx];
      int mn = numeric_limits<int>::max();
      for (int i = 0; i < 3; ++i) {
        auto nxt = lower_bound(days.begin(), days.end(), days[idx] + durations[i]) - days.begin();
        mn = min(mn, costs[i] + f(f, nxt));
      }
      return cache[idx] = mn;
    };

    return dp(dp, 0);
  }
};