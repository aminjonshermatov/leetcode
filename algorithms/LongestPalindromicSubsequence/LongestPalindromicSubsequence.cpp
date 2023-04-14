#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    const int n(s.size());
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }

    for (int len = 1; len < n; ++len) {
      for (int l = 0; l + len < n; ++l) {
        if (s[l] == s[l + len]) {
          dp[l][l + len] = max(dp[l][l + len], 2 + dp[l + 1][l + len - 1]);
        } else {
          auto nw = max(dp[l + 1][l + len], dp[l][l + len - 1]);
          dp[l][l + len] = max(dp[l][l + len], nw);
        }
      }
    }
    return dp[0][n - 1];
  }
};