#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    auto mx = *max_element(candies.begin(), candies.end());
    vector<bool> ans(candies.size());
    for (size_t i = 0u; i < candies.size(); ++i) {
      ans[i] = candies[i] + extraCandies >= mx;
    }
    return ans;
  }
};