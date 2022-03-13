#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        sort(nums.begin(), nums.end());

        for (int k = n - 1, j = n - 2, i = n - 3; i >= 0; --i, --j, --k) {
            if (nums[i] + nums[j] > nums[k] and nums[j] + nums[k] > nums[i] and nums[i] + nums[k] > nums[j])
                return nums[i] + nums[j] + nums[k];
        }
        return 0;
    }
};