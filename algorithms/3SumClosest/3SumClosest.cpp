#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int closest = nums[0] + nums[1] + nums[2],
                len = nums.size();

        for (int i = 0; i < len - 2; ++i) {
            int l = i + 1,
                    r = len - 1;

            while (l < r) {
                int cur = nums[i] + nums[l] + nums[r];

                if (abs(cur - target) < abs(closest - target)) closest = cur;

                if (cur < target) ++l;
                else if (cur > target) --r;
                else return cur;
            }
        }

        return closest;
    }
};