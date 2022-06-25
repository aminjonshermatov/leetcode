#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // 123 <- ok
        // 132 <- 122
        // 213 <- 113
        // 231 <- 233
        // 312 <- 112
        // 321 <- wrong
        const int n(nums.size());

        if (n <= 2) return true;

        bool used = false;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i - 1] <= nums[i] && nums[i] <= nums[i + 1]) continue;
            if (nums[i - 1] > nums[i] && nums[i] > nums[i + 1] || used) return false;

            int mx = max(nums[i - 1], max(nums[i], nums[i + 1])),
            int mn = min(nums[i - 1], min(nums[i], nums[i + 1]));

            if      (mn == nums[i - 1] && mx == nums[i]) nums[i] = nums[i + 1];
            else if (mn == nums[i] && mx == nums[i + 1]) nums[i - 1] = nums[i];
            else if (mn == nums[i + 1] && mx == nums[i]) nums[i + 1] = nums[i];
            else if (mn == nums[i] && mx == nums[i - 1]) nums[i - 1] = nums[i];
            used = true;
        }

        return true;
    }
};