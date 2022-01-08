#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0),
            len = static_cast<int>(nums.size());

        if ((sum & 1) || len == 1) return false;

        int target = sum / 2;
        vector<int> dp(target + 1, -1);

        function<bool(int, int)> dfs = [&](int idx, int curTarget) -> bool {
            if (curTarget == 0) return true;
            if (dp[curTarget] != -1) return dp[curTarget];

            int res = 0;
            for (int i = idx; i < nums.size() && res == 0; ++i) {
                if (curTarget - nums[i] < 0) continue;

                res = dfs(i + 1, curTarget - nums[i]);
            }

            dp[curTarget] = res;
            return static_cast<bool>(res);
        };

        return dfs(0, target);
    }
};