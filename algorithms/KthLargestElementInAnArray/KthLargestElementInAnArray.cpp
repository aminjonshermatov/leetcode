#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    for (int i = static_cast<int>(nums.size()); i >= 0 and k >= 0; --i, --k) {
      if (k == 0)
        return nums[i];
    }
    return {};
  }
  int findKthLargest(vector<int> &as, int k) {
    int lo = -1e5, hi = 1e5;
    while (hi - lo > 1) {
      auto mid = lo + (hi - lo) / 2;
      int cnt = 0;
      for (auto a : as) {
        cnt += a >= mid;
      }
      (cnt >= k ? lo : hi) = mid;
    }
    return lo;
  }
};