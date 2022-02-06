#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        int prev = INT_MAX, curCount = 0, origIdx = 0, newIdx = 0;

        while (origIdx < n) {
            if (nums[origIdx] != prev or curCount < 2) {
                if (prev != nums[origIdx]) curCount = 1;
                else ++curCount;

                prev = nums[origIdx];
                nums[newIdx++] = nums[origIdx++];
            } else {
                while (origIdx < n and nums[origIdx] == prev) ++origIdx;
            }
        }

        return newIdx;
    }
};