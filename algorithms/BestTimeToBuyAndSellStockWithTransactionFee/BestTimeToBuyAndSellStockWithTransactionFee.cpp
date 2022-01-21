#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<array<int, 2>> dp(prices.size(), {-1, -1});

        function<int(int, bool)> dfs = [&](int idx, bool isBuying) -> int {
            if (idx >= prices.size()) return 0;

            if (dp[idx][static_cast<int>(isBuying)] != -1) return dp[idx][static_cast<int>(isBuying)];

            int pass = dfs(idx + 1, isBuying);
            if (isBuying) {
                dp[idx][static_cast<int>(isBuying)] = max(pass, dfs(idx + 1, not isBuying) - prices[idx]);
            } else {
                dp[idx][static_cast<int>(isBuying)] = max(pass, dfs(idx + 1, not isBuying) + prices[idx] - fee);
            }

            return dp[idx][static_cast<int>(isBuying)];
        };

        return dfs(0, true);
    }

    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];

        for (size_t i{1}; i < prices.size(); ++i) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }

        return cash;
    }
};