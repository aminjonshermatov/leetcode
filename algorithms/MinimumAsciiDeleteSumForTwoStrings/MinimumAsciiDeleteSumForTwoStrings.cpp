#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int minimumDeleteSum(string a, string b) {
    const int n(a.size());
    const int m(b.size());
    a = "#" + a;
    b = "#" + b;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i] == b[j]) {
          dp[i][j] = a[i] - '\0' + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += a[i] - '\0';
    for (int i = 1; i <= m; ++i) ans += b[i] - '\0';
    return ans - dp[n][m] * 2;
  }
};