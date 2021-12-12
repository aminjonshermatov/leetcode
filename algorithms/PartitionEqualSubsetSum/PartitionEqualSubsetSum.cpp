#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0),
                len = static_cast<int>(nums.size());

        if ((sum & 1) || len == 1) return false;

        sum /= 2;

        vector<int> dp(sum + 1, -1);
        return dfs(nums, sum, 0, dp);
    }

    bool dfs(vector<int>& nums, int curSum, int idx, vector<int>& dp) {
        if (curSum == 0) return true;
        if (idx == nums.size()) return false;
        if (dp[curSum] != -1) return dp[curSum] == 1;

        for (int i = idx; i < static_cast<int>(nums.size()); ++i) {
            if (curSum - nums[i] >= 0 && dfs(nums, curSum - nums[i], i + 1, dp)) {
                dp[curSum] = 1;
                return true;
            }
        }

        dp[curSum] = 0;
        return false;
    }
};