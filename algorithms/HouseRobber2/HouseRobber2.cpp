#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();

        if (len == 1) return nums[0];
        return max(rob(nums, 0, len - 1), rob(nums, 1, len));
    }

    int rob(vector<int>& nums, int l, int r) {
        int prev2 = 0, prev1 = 0, res;

        for (int i = l; i < r; ++i) {
            res = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = res;
        }

        return res;
    }
};