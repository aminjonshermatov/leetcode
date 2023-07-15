#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int maxValue(vector<vector<int>>& events, int K) {
    const int n(events.size());
    vector<tuple<int, int, int>> evs(n);
    for (int i = 0; i < n; ++i) {
      evs[i] = tuple(events[i][0], events[i][1], events[i][2]);
    }
    sort(evs.begin(), evs.end(), [](const auto &lhs, const auto &rhs) {
      if (get<0>(lhs) != get<0>(rhs)) return get<0>(lhs) < get<0>(rhs);
      return get<2>(lhs) > get<2>(rhs);
    });

    vector<vector<int>> cache(n, vector<int>(K + 1, -1));
    auto dp = [&](auto &f, int i, int k) -> int {
      if (i >= n) return 0;
      if (k == 0) return 0;
      if (~cache[i][k]) return cache[i][k];
      return cache[i][k] = max(f(f, i + 1, k),
                               f(f, lower_bound(evs.begin(), evs.end(), tuple(get<1>(evs[i]) + 1, 0, 0)) - evs.begin(), k - 1) + get<2>(evs[i]));
    };
    return dp(dp, 0, K);
  }
};