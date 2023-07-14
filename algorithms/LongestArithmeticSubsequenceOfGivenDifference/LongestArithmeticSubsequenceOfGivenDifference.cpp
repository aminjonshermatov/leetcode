#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int>& arr, int diff) {
    map<int, int> dp{};
    int ans = 0;
    for (auto x : arr) {
      ans = max(ans, dp[x] = max(dp[x], dp[x - diff] + 1));
    }
    return ans;
  }
};