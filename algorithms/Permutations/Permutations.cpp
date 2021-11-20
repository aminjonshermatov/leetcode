#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();

        if (len == 1) {
            return {vector{nums}};
        }

        vector<vector<int>> res;

        for (int i = 0; i < len; ++i) {
            int temp = nums[i];
            nums.erase(nums.begin() + i);
            auto perm = permute(nums);

            for (auto el : perm) {
                el.push_back(temp);
                res.push_back(el);
            }

            nums.insert(nums.begin() + i, 1, temp);
        }

        return res;
    }
};