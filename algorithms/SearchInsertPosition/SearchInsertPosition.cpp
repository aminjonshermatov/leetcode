#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = static_cast<int>(nums.size());

        while (l < r) {
            int mid = (l + r) / 2;

            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                return mid;
            }
        }

        return l;
    }
};