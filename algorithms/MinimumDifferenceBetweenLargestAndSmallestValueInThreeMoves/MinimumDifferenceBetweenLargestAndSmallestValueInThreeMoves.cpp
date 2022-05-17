#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int n(nums.size());

        if (n <= 3) return 0;


        sort(nums.begin(), nums.end());

        // [3, 0]
        int diff = nums.back() - nums[3];
        // [2, 1]
        diff = min(diff, nums[n - 2] - nums[2]);
        // [1, 2]
        diff = min(diff, nums[n - 3] - nums[1]);
        // [0, 3]
        diff = min(diff, nums[n - 4] - nums.front());

        return diff;
    }
};