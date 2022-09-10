#include "bits/stdc++.h"

using namespace std;

class Solution {
    inline constexpr static const size_t S_ = 3u;
    inline constexpr static const size_t N_ = 101u;
    inline constexpr static const size_t M_ = 1001u;

    int cache[S_][N_][M_];
public:
    int maxProfit(int k, vector<int>& prices) {
        const auto N(prices.size());
        memset(cache, -1, sizeof(int) * S_ * N_ * M_);

        function<int(int, int, int)> dfs = [&](int idx, int kleft, int sell) -> int {
            if (idx == N || kleft == 0) return 0;
            if (cache[sell][kleft][idx] != -1) return cache[sell][kleft][idx];

            int ans;
            if (sell == 1) {
                ans = max(dfs(idx + 1, kleft - 1, 0) + prices[idx], dfs(idx + 1, kleft, 1));
            } else {
                ans = max(dfs(idx + 1, kleft, 1) - prices[idx], dfs(idx + 1, kleft, 0));
            }

            return cache[sell][kleft][idx] = ans;
        };

        return dfs(0, k, 0);
    }
};