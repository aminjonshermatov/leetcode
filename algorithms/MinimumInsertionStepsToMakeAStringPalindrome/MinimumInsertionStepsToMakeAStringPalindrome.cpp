#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int minInsertions(string s) {
    const int n(s.size());
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][1] = 1;
    }

    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        if (s[i] == s[i + len - 1]) {
          dp[i][len] = 2 + dp[i + 1][len - 2];
        } else {
          dp[i][len] = max(dp[i + 1][len - 1], dp[i][len - 1]);
        }
      }
    }

    return n - dp[0][n];
  }
};