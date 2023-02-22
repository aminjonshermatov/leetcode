#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int shipWithinDays(vector<int>& W, int days) {
    auto ok = [&](int lim) -> bool {
      if (*max_element(W.begin(), W.end()) > lim) return false;
      int d = 0, cur = 0;
      for (auto w : W) {
        if (w + cur > lim) {
          ++d;
          cur = 0;
        }
        cur += w;
      }
      return ++d <= days;
    };

    int lo = 1, hi = accumulate(W.begin(), W.end(), 0);
    while (hi - lo > 1) {
      auto mid = lo + (hi - lo) / 2;
      (ok(mid) ? hi : lo) = mid;
    }
    return hi;
  }
};