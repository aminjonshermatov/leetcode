#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    array<int, 32> fr{};
    fr.fill(0);
    for (auto x : nums) {
      for (int i = 31; i >= 0; --i) {
        if (x >> i & 1) {
          ++fr[i];
        }
      }
    }
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
      if (fr[i] % 3 == 1) {
        ans |= 1 << i;
      }
    }
    return ans;
  }
};