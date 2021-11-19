#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int len = nums.size();

        for (size_t i = 0; i < len; ++i) {
            for (size_t j = i + 1; j < len; ++j) {
                int l = j + 1,
                        r = len - 1;

                while (l < r) {
                    long long sum = 0LL + nums[i] + nums[j] + nums[l] + nums[r];

                    if (sum < target) ++l;
                    else if (sum > target) --r;
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};

                        res.push_back(temp);

                        while (l < r && nums[l] == temp[2]) ++l;
                        while (l < r && nums[r] == temp[3]) --r;
                    }
                }

                while (j + 1 < len && nums[j + 1] == nums[j]) ++j;
            }

            while (i + 1 < len && nums[i + 1] == nums[i]) ++i;
        }

        return res;
    }
};