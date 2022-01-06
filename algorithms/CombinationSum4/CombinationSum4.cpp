#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        if (nums.empty() || *nums.begin() > target) return 0;

        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; ++i) {
            for (const auto n : nums) {
                if (i - n < 0) break;

                dp[i] += dp[i - n];
            }
        }

        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        if (nums.empty() || *nums.begin() > target) return 0;

        unordered_map<int, int> cache;
        cache[0] = 1;

        function<int(int)> dfs = [&dfs, &cache, &nums](int curT) -> int {
            if (cache[curT] > 0) return cache[curT];

            int res = 0;
            for (const auto n : nums) {
                if (curT - n < 0) break;

                res += dfs(curT - n);
            }

            return cache[curT] = res;
        };

        return dfs(target);
    }
};