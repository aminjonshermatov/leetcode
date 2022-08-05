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
};

class Solution {
    inline static const int SIZE = 1001;
    vector<int> nums_;
    int cache[SIZE];

    auto backtrack(int t) {
        if (t == 0) { return 1; }
        if (cache[t] != -1) return cache[t];
        int local = 0;

        for (size_t i = 0; i < nums_.size(); ++i) {
            if (t - nums_[i] < 0) continue;
            local += backtrack(t - nums_[i]);
        }

        return cache[t] = local;
    };
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        nums_ = nums;

        memset(cache, -1, SIZE * sizeof(int));

        return backtrack(target);;
    }
};