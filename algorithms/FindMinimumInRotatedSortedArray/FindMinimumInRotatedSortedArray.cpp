#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        const auto n = nums.size();

        int lessThan = 0;
        for (int b = n >> 1; b >= 1; b >>= 1) {
            while (lessThan + b < n and nums[lessThan + b] >= nums[0]) lessThan += b;
        }
        ++lessThan;
        if (lessThan >= n) lessThan = 0;

        return nums[lessThan];
    }

    int findMin(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        int lo = 0, hi = n;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (nums[mid] >= nums.front()) lo = mid + 1;
            else hi = mid;
        }

        return lo < n ? nums[lo] : nums.front();
    }
};