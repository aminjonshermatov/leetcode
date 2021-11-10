#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyIdx = 0,
            sellIdx = 1,
            profit = 0,
            len = prices.size();

        while (sellIdx < len) {
            if (prices[buyIdx] >= prices[sellIdx]) {
                ++buyIdx;
                ++sellIdx;
            } else {
                profit += prices[sellIdx] - prices[buyIdx];
                buyIdx = sellIdx;
                ++sellIdx;
            }
        }

        return profit;
    }
};