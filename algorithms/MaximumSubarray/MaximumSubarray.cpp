#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>&& nums) {
        int maxEl = nums[0], cur = 0;

        for (const auto& n : nums) {
            if (cur < 0) {
                cur = 0;
            }

            cur += n;
            maxEl = max(maxEl, cur);
        }

        return maxEl;
    }
};