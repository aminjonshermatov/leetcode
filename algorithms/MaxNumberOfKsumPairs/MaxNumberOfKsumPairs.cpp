#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int lo = 0, hi = static_cast<int>(nums.size()) - 1;

        int count = 0;
        while (lo < hi) {
            int target = nums[lo] + nums[hi];

            if (target < k) ++lo;
            else if (target > k) --hi;
            else {
                ++count;
                ++lo;
                --hi;
            }
        }

        return count;
    }
};