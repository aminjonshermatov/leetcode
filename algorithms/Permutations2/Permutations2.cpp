#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        backtrack(res,nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int> nums, int pos) {
        int len = nums.size();

        if (pos == len) {
            res.emplace_back(nums);
            return;
        }

        for (int i = pos; i < len; ++i) {
            if (i != pos && nums[i] == nums[pos]) continue;

            swap(nums[i], nums[pos]);
            backtrack(res, nums, pos + 1);
        }
    }
};