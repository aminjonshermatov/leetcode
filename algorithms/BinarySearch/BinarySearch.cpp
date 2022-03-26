#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = static_cast<int>(nums.size());

        for (auto lo{0}, hi{n}; lo < hi;) {
            auto mid = lo + ((hi - lo) >> 1);

            if (nums[mid] < target) lo = mid + 1;
            else if (nums[mid] > target) hi = mid;
            else return mid;
        }

        return -1;
    }
};