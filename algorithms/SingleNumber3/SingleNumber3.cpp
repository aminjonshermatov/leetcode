#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // sort + linear search
    // TC - O(n*long(n)), SC - O(1)
    vector<int> singleNumber(vector<int>& nums) {
        int len = (int)nums.size();

        if (len == 2) return nums;

        sort(begin(nums), end(nums));

        vector<int> res;

        for (int i = 0; i < len; ++i) {
            if (nums[i + 1] == nums[i]) {
                ++i;
            } else {
                res.push_back(nums[i]);
            }
        }

        return res;
    }

    // bit mask
    // TC - O(n), SC - O(1)
    vector<int> singleNumber(vector<int>& nums) {
        int xy = 0;

        for (const auto& el : nums) xy ^= el;

        int mask = xy & ~(xy - 1);

        int x = 0, y = 0;

        for (const auto& el : nums) {
            if (el & mask) x ^= el;
            else y ^= el;
        }

        return {x, y};
    }
};