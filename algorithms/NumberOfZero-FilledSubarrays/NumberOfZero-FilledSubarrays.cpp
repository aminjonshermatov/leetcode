#include "bits/stdc++.h"

using namespace std;

class Solution {
  using ll = long long;
public:
  ll zeroFilledSubarray(vector<int>& nums) {
    ll ans = 0, cur = 0;
    for (auto x : nums) {
      if (x == 0) {
        ++cur;
      } else {
        ans += cur * (cur + 1) / 2;
        cur = 0;
      }
    }
    ans += cur * (cur + 1) / 2;

    return ans;
  }
};