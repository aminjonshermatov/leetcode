#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len, -1));

        function<int(int, int)> dfs = [&](int l, int r) -> int {
            if (l > r) return 0;
            if (dp[l][r] != -1) return dp[l][r];

            dp[l][r] = 0;
            int partial = nums[l - 1] * nums[r + 1];

            for (int i = l; i <= r; ++i) {
                int coins = partial * nums[i];
                coins += dfs(l, i - 1) + dfs(i + 1, r);
                dp[l][r] = max(dp[l][r], coins);
            }

            return dp[l][r];
        };

        return dfs(1, nums.size() - 2);
    }
};