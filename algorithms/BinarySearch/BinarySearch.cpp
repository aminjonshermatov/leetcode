#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (size_t lo = 0, hi = nums.size(); lo < hi) {
            auto mid = lo + ((hi - lo) >> 1);

            if (nums[mid] > target) hi = mid;
            else if (nums[mid] < target) lo = mid + 1;
            else return mid;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (auto lo = lower_bound(nums.begin(), nums.end(), target); lo == nums.end() || *lo != target) return -1;
        else return lo - nums.begin();
    }
};