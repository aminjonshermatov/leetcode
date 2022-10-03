#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        const int N(nums.size());
        const auto [mn, mx] = minmax_element(nums.begin(), nums.end());
        if (target > *mx || target < *mn) return {};

        vector<int> fr(*mx - *mn + 1);

        for (auto num : nums) ++fr[num - *mn];

        int offset = 0;
        for (int i = 0; i < *mx - *mn + 1 && *mn + i < target; offset += fr[i++]) { }

        vector<int> res(fr[target - *mn]);
        iota(res.begin(), res.end(), offset);

        return res;
    }
};