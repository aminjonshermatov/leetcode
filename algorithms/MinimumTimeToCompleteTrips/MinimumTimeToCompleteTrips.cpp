#include "bits/stdc++.h"

using namespace std;

class Solution {
  using ll = long long;
public:
  ll minimumTime(vector<int>& time, int totalTrips) {
    auto ok = [&](ll t) -> bool {
      ll tot = 0;
      for (auto x : time) if ((tot += t / x) >= totalTrips) return true;
      return tot >= totalTrips;
    };

    ll lo = 0, hi = 1e16;
    while (hi - lo > 1) {
      auto mid = lo + (hi - lo) / 2;
      (ok(mid) ? hi : lo) = mid;
    }
    return hi;
  }
};