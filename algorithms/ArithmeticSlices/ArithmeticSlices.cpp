#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        vector<int> diff(n - 1);

        for (int i = 1; i < n; ++i) diff[i - 1] = nums[i] - nums[i - 1];

        int res = 0, k = 1;

        for (int i = 1; i < n - 1; ++i) {
            if (diff[i] == diff[i - 1]) res += k++;
            else k = 1;
        }

        return res;
    }
};