#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros = count(nums.begin(), nums.end(), 0);

        const int n = nums.size();
        if (zeros < 2) return n - 1;

        int preLast = -1, last = -1, res = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                preLast = last;
                last = i;
            }

            res = max(res, i - preLast - 1);
        }

        return res;
    }
};