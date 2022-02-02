#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int n = static_cast<int>(coins.size());
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        const function<int(const int, const int)> dfs = [&](const int idx, const int am) -> int {
            if (am == 0) return 1;
            if (dp[idx][am] != -1) return dp[idx][am];

            int total = 0;
            for (int i = idx; i < n; ++i) {
                if (am - coins[i] >= 0) total += dfs(i, am - coins[i]);
            }

            return dp[idx][am] = total;
        };

        return dfs(0, amount);
    }
};