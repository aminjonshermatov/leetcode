#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &ps, int fee) {
    const int n(ps.size());
    vector<array<int, 2>> cache(n, array<int, 2>{0, 0});
    vector<array<bool, 2>> seen(n, array<bool, 2>{false, false});
    auto dp = [&](auto &f, int day, bool buy) -> int {
      if (day >= n)
        return buy ? 0 : -1e9;
      if (seen[day][buy])
        return cache[day][buy];

      auto loc = f(f, day + 1, buy);
      if (buy)
        loc = max(loc, f(f, day + 1, false) - ps[day]);
      else
        loc = max(loc, f(f, day + 1, true) + ps[day] - fee);
      seen[day][buy] = true;
      return cache[day][buy] = loc;
    };
    return dp(dp, 0, true);
  }

  int maxProfit(vector<int> &prices, int fee) {
    int cash = 0, hold = -prices[0];

    for (size_t i{1}; i < prices.size(); ++i) {
      cash = max(cash, hold + prices[i] - fee);
      hold = max(hold, cash - prices[i]);
    }

    return cash;
  }
};