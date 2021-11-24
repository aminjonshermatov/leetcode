#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> cache;
    int total = 0;

    int findTargetSumWays(vector<int>& nums, int target) {
        for (const auto& n : nums) total += n;

        cache.resize(21, vector<int>(2 * total + 1, -1));

        if (total < abs(target)) return 0;

        return backtrack(nums, target, 0, 0);
    }

    int backtrack(vector<int>& nums, int target, int curSum, int idx) {
        if (idx >= nums.size()) {
            return static_cast<int>(curSum == target);
        }

        if (cache[idx][total + curSum] != -1) return cache[idx][total + curSum];

        return cache[idx][total + curSum] = backtrack(nums, target, curSum + nums[idx], idx + 1) +
                                            backtrack(nums, target, curSum - nums[idx], idx + 1);
    }
};