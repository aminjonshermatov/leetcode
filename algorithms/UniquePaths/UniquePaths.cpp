#include "bits/stdc++.h"

using namespace std;

class Solution {
    uint32_t dp[101u][101u];

public:
    int uniquePaths(int n, int m) {
        for (size_t i = 0u; i < n; ++i) dp[i][0u] = 1u;
        for (size_t j = 1u; j < m; ++j) dp[0u][j] = 1u;

        for (size_t i = 1u; i < n; ++i) {
            for (size_t j = 1u; j < m; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        return dp[n - 1][m - 1];
    }
};