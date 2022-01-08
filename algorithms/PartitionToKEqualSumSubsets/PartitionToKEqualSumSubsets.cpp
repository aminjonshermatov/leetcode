#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) return true;

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return false;

        int target = sum / k;

        vector<int> dp(target + 1, -1);
        sort(nums.begin(), nums.end(), greater<>());

        function<bool(int, int)> dfs = [&](int idx, int curTarget) -> bool {
            if (curTarget == 0) return true;
            if (idx >= nums.size()) return false;
            if (dp[curTarget] != -1) return dp[curTarget];

            int res = 0;
            for (int i = idx; i < nums.size() && !res; ++i) {
                if (nums[i] < 0 || curTarget - nums[i] < 0) continue;
                res = dfs(i + 1, curTarget - nums[i]);
                if (res) nums[i] = -1;
            }

            return dp[curTarget] = res;
        };

        int res = true;
        int idx = 0;
        while (k-- && res) {
            while (idx < nums.size() && nums[idx] < 0) ++idx;
            res = dfs(idx, target);
            dp.assign(target + 1, -1);
        }

        return res;
    }
};