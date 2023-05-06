#include "bits/stdc++.h"

using namespace std;

class Solution {
  static constexpr int mod = 1e9 + 7;
  int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
      if (b & 1) ans = 1ll * a * ans % mod;
      a = 1ll * a * a % mod;
      b >>= 1;
    }
    return ans;
  }
public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      auto j = int(upper_bound(nums.begin() + i, nums.end(), target - nums[i]) - nums.begin());
      if (i < j) ans = (ans + power(2, j - i - 1)) % mod;
    }
    return ans;
  }
};