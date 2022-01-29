#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        const int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n - 1;

            while (l < r) {
                int target = nums[i] + nums[l] + nums[r];

                if (target < 0) ++l;
                else if (target > 0) --r;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;

                    while (l < r and nums[l] == nums[l - 1]) ++l;
                }
            }

            while (i < n - 1 and nums[i] == nums[i + 1]) ++i;
        }

        return res;
    }
};