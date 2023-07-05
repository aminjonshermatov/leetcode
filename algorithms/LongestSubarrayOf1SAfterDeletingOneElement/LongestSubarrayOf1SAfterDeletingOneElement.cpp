#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int zeros = count(nums.begin(), nums.end(), 0);

    const int n = nums.size();
    if (zeros < 2)
      return n - 1;

    int preLast = -1, last = -1, res = 0;

    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        preLast = last;
        last = i;
      }

      res = max(res, i - preLast - 1);
    }

    return res;
  }
  int longestSubarray(vector<int> &as) {
    const int n(as.size());
    vector<pair<int, int>> xs;
    xs.emplace_back(as[0], 1);
    for (int i = 1; i < n; ++i) {
      if (as[i] == as[i - 1]) {
        ++xs.back().second;
      } else {
        xs.emplace_back(as[i], 1);
      }
    }
    int ans = 0;
    for (int i = 0; i < xs.size(); ++i) {
      if (xs[i].first == 1) {
        ans = max(ans, xs[i].second - 1);
      } else {
        bool has_left = i > 0;
        bool has_right = i + 1 < xs.size();
        if (has_left && has_right && xs[i - 1].first == 1 &&
            xs[i].second == 1 && xs[i + 1].first == 1) {
          ans = max(ans, xs[i - 1].second + xs[i + 1].second);
        }
        if (has_left && xs[i - 1].first == 1) {
          ans = max(ans, xs[i - 1].second);
        }
        if (has_right && xs[i + 1].first == 1) {
          ans = max(ans, xs[i + 1].second);
        }
      }
    }
    return ans;
  }
};