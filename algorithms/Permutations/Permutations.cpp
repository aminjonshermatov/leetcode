#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();

        function<void(int)> backtrack = [&](int pos) -> void {
            if (pos == len) {
                res.emplace_back(nums);
                return;
            }

            for (int i = pos; i < len; ++i) {
                swap(nums[i], nums[pos]);
                backtrack(pos + 1);
                swap(nums[i], nums[pos]);
            }
        };

        backtrack(0);

        return res;
    }
};