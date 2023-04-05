#include "bits/stdc++.h"

using namespace std;

class Solution {
  using ll = long long;
public:
  int minimizeArrayValue(vector<int>& nums) {
    const int n(nums.size());
    auto can = [&](ll x) -> bool {
      ll sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += nums[i];
        if (x < (sum + i) / (i + 1)) return false;
      }
      return true;
    };

    ll lo = -1, hi = accumulate(nums.begin(), nums.end(), 0ll);
    while (hi - lo > 1) {
      auto mid = lo + (hi - lo) / 2;
      (can(mid) ? hi : lo) = mid;
    }
    return hi;
  }
};