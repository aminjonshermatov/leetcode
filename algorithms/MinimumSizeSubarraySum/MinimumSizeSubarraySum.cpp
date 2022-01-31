#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        int minL = INT_MAX, l = 0, r = 0, window = 0;

        while (r < n) {
            window += nums[r];

            while (window >= target) {
                minL = min(minL, r - l + 1);
                window -= nums[l++];
            }

            ++r;
        }

        return minL == INT_MAX ? 0 : minL;
    }
};