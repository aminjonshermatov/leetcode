#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n(prices.size());
        array<vector<int>, 2> dp;
        for (int i = 0; i < 2; ++i) dp[i].assign(n, -1);

        auto dfs = [&](auto self, int idx, int is_buy) -> int {
            if (idx >= n) return 0;
            if (dp[is_buy][idx] != -1) return dp[is_buy][idx];

            auto cooldown = self(self, idx + 1, is_buy);
            if (is_buy == 1) {
                auto buy = self(self, idx + 1, 0) - prices[idx];
                dp[is_buy][idx] = max(cooldown, buy);
            } else {
                auto sell = self(self, idx + 2, 1) + prices[idx];
                dp[is_buy][idx] = max(cooldown, sell);
            }

            return dp[is_buy][idx];
        };

        return dfs(dfs, 0, 1);
    }
};