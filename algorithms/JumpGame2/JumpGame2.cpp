#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[nums.size() - 1] = 0;

        for (int i = nums.size() - 2; i >= 0; --i) {
            int res = -1;
            for (int j = i + 1; nums[i] != 0 and j < i + 1 + nums[i] and j < nums.size(); ++j) {
                if (dp[j] == -1) continue;
                if (res == -1) res = 1 + dp[j];
                else res = min(res, 1 + dp[j]);
            }
            dp[i] = res;
        }

        return dp[0];
    }
};