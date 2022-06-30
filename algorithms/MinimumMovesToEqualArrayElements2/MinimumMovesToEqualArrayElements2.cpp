#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        const int n(nums.size());
        const int mid = n >> 1;

        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i != mid) ans += abs(nums[mid] - nums[i]);
        }

        return ans;
    }
};