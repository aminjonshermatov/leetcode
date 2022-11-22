#include "bits/stdc++.h"

using namespace std;

class Solution {
    static inline constexpr int inf = numeric_limits<int>::max();
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = 1; j * j <= i; ++j) dp[i] = min(dp[i], dp[i - j * j] + 1);

        return dp[n];
    }
};