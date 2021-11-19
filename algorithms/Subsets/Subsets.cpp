#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        dfs(nums, res, subset, 0);

        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int pos) {
        if (pos >= nums.size()) {
            res.emplace_back(subset);
            return;
        }

        subset.push_back(nums[pos]);
        dfs(nums, res, subset, pos + 1);

        auto position = find(subset.begin(), subset.end(), nums[pos]);
        subset.erase(position);
        dfs(nums, res, subset, pos + 1);
    }
};