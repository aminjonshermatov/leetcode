#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // (day, isBuying) -> maxProfit
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));

        function<int(int, bool)> dfs = [&](int day, bool isBuying) -> int {
            if (day >= prices.size()) return 0;

            if (dp[day][static_cast<int>(isBuying)] != -1) return dp[day][static_cast<int>(isBuying)];

            int cooldown = dfs(day + 1, isBuying);
            if (isBuying) {
                int buy = dfs(day + 1, not isBuying) - prices[day];
                dp[day][static_cast<int>(isBuying)] = max(buy, cooldown);
            } else {
                int sell = dfs(day + 2, not isBuying) + prices[day];
                dp[day][static_cast<int>(isBuying)] = max(sell, cooldown);
            }

            return dp[day][static_cast<int>(isBuying)];
        };

        return dfs(0, true);
    }
};