#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size(), {1, 1});
        int resCount = 0, resLen = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
            int maxLen = 1, maxCount = 1;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    auto [len, cnt] = dp[j];

                    if (len + 1 == maxLen) {
                        maxCount += cnt;
                    } else if (len + 1 > maxLen) {
                        maxLen = len + 1;
                        maxCount = cnt;
                    }
                }
            }

            if (maxLen > resLen) {
                resLen = maxLen;
                resCount = maxCount;
            } else if (maxLen == resLen) {
                resCount += maxCount;
            }

            dp[i] = {maxLen, maxCount};
        }

        return resCount;
    }
};