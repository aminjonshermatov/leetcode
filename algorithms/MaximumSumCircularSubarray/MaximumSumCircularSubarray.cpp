#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN,
            cur = 0;

        for (int i = 0; i < n; ++i) {
            cur = max(cur + nums[i], nums[i]);
            ans = max(ans, cur);
        }

        vector<int> rightToLeftSum(n);
        rightToLeftSum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightToLeftSum[i] = rightToLeftSum[i + 1] + nums[i];
        }

        vector<int> maxRightEl(n);
        maxRightEl[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxRightEl[i] = max(rightToLeftSum[i], maxRightEl[i + 1]);
        }

        int leftSum = 0;
        for (int i = 0; i < n - 2; ++i) {
            leftSum += nums[i];
            ans = max(ans, leftSum + maxRightEl[i + 2]);
        }

        return ans;
    }
};