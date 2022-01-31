#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        const int n = static_cast<int>(nums.size());
        int res = 0, prod = 1, l = 0, r = 0;

        while (r < n) {
            prod *= nums[r];

            while (prod >= k) prod /= nums[l++];
            res += r++ - l + 1;
        }

        return res;
    }
};