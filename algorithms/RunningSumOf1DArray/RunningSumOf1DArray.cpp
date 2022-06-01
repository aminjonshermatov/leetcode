#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        const int n(nums.size());
        vector<int> ans(n, 0);
        ans.front() = nums.front();
        for (int i = 1; i < n; ++i) ans[i] += ans[i - 1] + nums[i];

        return ans;
    }
};