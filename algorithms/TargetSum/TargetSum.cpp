#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> cache;

        return backtrack(nums, cache, target, 0);
    }

    int backtrack(vector<int>& nums, map<pair<int, int>, int>& cache, int curSum, int idx) {
        if (idx >= nums.size()) return static_cast<int>(curSum == 0);

        if (cache.count({idx, curSum}) > 0) return cache.at({idx, curSum});

        return cache[{idx, curSum}] = backtrack(nums, cache, curSum + nums[idx], idx + 1) +
                                      backtrack(nums, cache, curSum - nums[idx], idx + 1);
    }
};