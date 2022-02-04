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

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        vector<vector<int>> res;
        list<int> cur;

        const function<void(const int)> dfs = [&](const int idx) -> void {
            if (idx >= n) {
                res.push_back(vector<int>(cur.begin(), cur.end()));
                return;
            }

            res.push_back(vector<int>(cur.begin(), cur.end()));

            for (int i = idx; i < n; ++i) {
                cur.push_back(nums[i]);
                dfs(i + 1);
                cur.pop_back();
            }
        };

        dfs(0);

        return res;
    }
};