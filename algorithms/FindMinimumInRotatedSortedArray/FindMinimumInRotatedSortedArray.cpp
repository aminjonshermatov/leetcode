#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        const auto n = nums.size();

        int lessThan = 0;
        for (int b = n >> 1; b >= 1; b >>= 1) {
            while (lessThan + b < n and nums[lessThan + b] >= nums[0]) lessThan += b;
        }
        ++lessThan;
        if (lessThan >= n) lessThan = 0;

        return nums[lessThan];
    }
};