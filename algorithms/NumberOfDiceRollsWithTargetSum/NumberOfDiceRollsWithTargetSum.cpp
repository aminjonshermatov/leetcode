#include "bits/stdc++.h"

using namespace std;

class Solution {
    using ll = long long;
    static constexpr ll MOD = 1e9 + 7;

public:
    int numRollsToTarget(int n, int k, int target) {
        // dp[n][amount] - earn amount sum with n dices
        vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, 0));
        for (int i = 1; i <= k && i <= target; ++i) dp[1][i] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int s = 1; s <= target; ++s) {
                for (int kk = 1; kk <= k; ++kk) {
                    if (s - kk >= 0) dp[i][s] += dp[i - 1][s - kk], dp[i][s] %= MOD;
                }
            }
        }

        return dp[n][target];
    }
};