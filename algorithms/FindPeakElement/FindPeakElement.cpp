#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n(nums.size());

        int lo = 0, hi = n;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (mid + 1 < n && nums[mid + 1] > nums[mid]) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    }
};