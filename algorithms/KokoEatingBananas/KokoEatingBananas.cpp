#include "bits/stdc++.h"

using namespace std;

class Solution {
  using i64 = ::int64_t;
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    auto ok = [&](int k) -> bool {
      i64 hh = 0;
      for (auto s : piles) hh += (i64(s) + k - 1) / k;
      return hh <= h;
    };

    int lo = 0, hi = 1e9;
    while (hi - lo > 1) {
      auto mid = lo + (hi - lo) / 2;
      (ok(mid) ? hi : lo) = mid;
    }
    return hi;
  }
};