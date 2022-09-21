#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even = accumulate(nums.begin(), nums.end(), 0, [](auto acc, auto el) { return el & 1 ? acc : acc + el; });

        vector<int> res;
        res.reserve(queries.size());
        for (const auto &q : queries) {
            auto newV = abs(nums[q[1]] + q[0]);

            if ((nums[q[1]] & 1) == 0) even -= nums[q[1]];
            nums[q[1]] += q[0];
            if ((newV & 1) == 0) even += nums[q[1]];

            res.emplace_back(even);
        }

        return res;
    }
};