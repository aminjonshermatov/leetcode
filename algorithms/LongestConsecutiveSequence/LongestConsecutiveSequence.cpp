#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // O(n*log(n)) - TC, O(n) - SC
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;

        for (const auto& n : nums) hashSet.insert(n);

        bool isFirst = true;
        int maxSeq = 0,
                prevN = 0,
                curCount = 0;

        for (const auto& n : hashSet) {
            if (isFirst) {
                curCount = 1;
                isFirst = false;
            } else if (n - 1 == prevN) {
                ++curCount;
            } else {
                curCount = 1;
            }

            prevN = n;
            maxSeq = max(maxSeq, curCount);
        }

        return maxSeq;
    }

    // O(n*log(n)) - TC, O(1) - SC
    int longestConsecutive(vector<int>& nums) {
        const int n(nums.size());

        sort(nums.begin(), nums.end());

        int ans = nums.empty() ? 0 : 1, len = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] + 1 == nums[i]) ++len;
            else if (nums[i - 1] == nums[i]) continue;
            else len = 1;

            ans = max(ans, len);
        }

        return ans;
    }
};