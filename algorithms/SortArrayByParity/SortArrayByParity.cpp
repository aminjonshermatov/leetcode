#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lo = 0, hi = static_cast<int>(nums.size()) - 1;

        while (lo < hi) {
            if ((nums[hi] & 1) == 0) {
                swap(nums[lo++], nums[hi]);
            } else --hi;
        }

        return nums;
    }
};