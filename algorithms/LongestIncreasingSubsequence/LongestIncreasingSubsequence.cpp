#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // dp: O(n^2) - TC, O(n^2) - SC
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }

    // sorting: O(n*logn) - TC, O(n) - SC
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for (auto num : nums) {
            auto lo = lower_bound(lis.begin(), lis.end(), num);

            if (lo == lis.end()) lis.push_back(num);
            else *lo = num;
        }

        return lis.size();
    }
};