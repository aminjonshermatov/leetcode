#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        const int n = static_cast<int>(nums.size());

        int lo = 0, hi = n;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (nums[mid] < target) lo = mid + 1;
            else if (nums[mid] > target) hi = mid;
            else return mid;
        }

        return lo;
    }
};