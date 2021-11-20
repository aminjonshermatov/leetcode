#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> subset;

        dfs(res, subset, nums, 0);

        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int pos) {
        res.emplace_back(subset);

        for (int i = pos; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            dfs(res, subset, nums, i + 1);
            subset.pop_back();

            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
    }
};