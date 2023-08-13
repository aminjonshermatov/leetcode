#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool validPartition(vector<int>& as) {
    const auto n = int(as.size());
    vector<bool> dp(n + 1, false);
    dp[n] = true;
    for (int i = n - 1; i >= 0; --i) {
      bool loc = false;
      if (n - i >= 2 && as[i] == as[i + 1]) {
        loc |= dp[i + 2];
      }
      if (n - i >= 3 && as[i] == as[i + 1] && as[i + 1] == as[i + 2]) {
        loc |= dp[i + 3];
      }
      if (n - i >= 3 && as[i] + 1 == as[i + 1] && as[i + 1] + 1 == as[i + 2]) {
        loc |= dp[i + 3];
      }
      dp[i] = loc;
    }
    return dp[0];
  }
};