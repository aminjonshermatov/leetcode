#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n(nums.size());

        int ans = numeric_limits<int>::min(), cur = 0;
        for (auto num : nums) {
            cur = max(cur + num, num);
            ans = max(ans, cur);
        }

        vector<int> sf(n);
        sf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) sf[i] = nums[i] + sf[i + 1];
        vector<int> mx_sf(n + 1);
        mx_sf[n - 1] = sf[n - 1];
        for (int i = n - 2; i >= 0; --i) mx_sf[i] = max(sf[i], mx_sf[i + 1]);

        int left = 0;
        for (int i = 0; i < n; ++i) {
            left += nums[i];
            ans = max(ans, left + mx_sf[i + 1]);
        }

        return ans;
    }
};