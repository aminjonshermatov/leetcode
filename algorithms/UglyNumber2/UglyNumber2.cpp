#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums = {1};

        int idx2 = 0,
            idx3 = 0,
            idx5 = 0;

        while (nums.size() < n) {
            nums.push_back(min(nums[idx2] * 2, min(nums[idx3] * 3, nums[idx5] * 5)));

            if (nums.back() == nums[idx2] * 2) ++idx2;
            if (nums.back() == nums[idx3] * 3) ++idx3;
            if (nums.back() == nums[idx5] * 5) ++idx5;
        }

        return nums.back();
    }
};