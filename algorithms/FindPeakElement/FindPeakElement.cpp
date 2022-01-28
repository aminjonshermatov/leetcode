#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi) {
            const int mid = lo + ((hi - lo) >> 1);

            if (nums[mid] > nums[mid + 1]) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};