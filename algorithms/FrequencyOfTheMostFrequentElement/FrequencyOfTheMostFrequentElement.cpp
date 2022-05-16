#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int64_t i = 0, j = 0, ans = 0, sum = 0;
        for (; j < nums.size(); ++j) {
            sum += nums[j];

            if ((j - i + 1) * nums[j] - sum > k) sum -= nums[i++];
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};