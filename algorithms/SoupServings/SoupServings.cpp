#include "bits/stdc++.h"

using namespace std;

class Solution {
  static inline constexpr array<pair<int, int>, 4> ops{pair(4, 0), pair(3, 1), pair(2, 2), pair(1, 3)};
public:
  double soupServings(int n) {
    map<pair<int, int>, double> cache;
    auto P = [&](auto &f, int a, int b) -> double {
      if (a <= 0 && b <= 0) return .5;
      if (a <= 0) return 1;
      if (b <= 0) return 0;
      if (cache.count(pair(a, b)) > 0) return cache.at(pair(a, b));
      double loc = 0;
      for (auto [da, db] : ops) {
        loc += f(f, a - da, b - db) / 4;
      }
      return cache[pair(a, b)] = loc;
    };
    const int m = (n + 24) / 25;
    for (int k = 1; k <= m; ++k) {
      if (P(P, k, k) > 1 - 1e-5) {
        return 1;
      }
    }
    return P(P, m, m);
  }
};