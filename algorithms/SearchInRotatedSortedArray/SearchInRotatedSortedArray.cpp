#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        const function<int(int)> firstLess = [&](int k) -> int {
            int lo = 0, hi = nums.size();

            while (lo < hi) {
                const int mid = lo + ((hi - lo) >> 1);

                if (k > nums[mid]) hi = mid;
                else lo = mid + 1;
            }

            return hi;
        };

        const function<int(int, int)> binarySearch = [&](int lo, int hi) -> int {
            while (lo < hi) {
                const int mid = lo + ((hi - lo) >> 1);

                if (target < nums[mid]) hi = mid;
                else if (target > nums[mid]) lo = mid + 1;
                else return mid;
            }

            return -1;
        };

        const auto pivot = firstLess(nums[0]);
        const auto first = binarySearch(0, pivot);

        if (first != -1) return first;
        return binarySearch(pivot, nums.size());
    }
};