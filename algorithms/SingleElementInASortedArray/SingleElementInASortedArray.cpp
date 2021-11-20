#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();

        if (len == 1) return nums[0];

        int l = 0,
            r = len - 1;

        while (l < r) {
            int mid = (l + r) >> 1;

            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) l = mid + 1;
                else r = mid;
            } else {
                if (mid + 1 < len) {
                    if (nums[mid] == nums[mid + 1]) r = mid;
                    else l = mid + 1;
                } else {
                    return nums[mid];
                }
            }
        }

        return nums[l];
    }
};