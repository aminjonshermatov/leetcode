#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();

        vector<int> dp(len - 1);

        for (int i = 1; i < len; ++i) {
            dp[i - 1] = nums[i] - nums[i - 1];
        }

        int res = 0,
            k = 1;

        for (int i = 1; i < len - 1; ++i) {
            if (dp[i] == dp[i - 1]) res += k++;
            else k = 1;
        }

        return res;
    }
};