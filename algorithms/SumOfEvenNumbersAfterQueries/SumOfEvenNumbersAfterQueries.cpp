#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even = 0;
        for (const auto num : nums) if ((num & 1) == 0) even += num;

        vector<int> res;
        res.reserve(queries.size());
        for (const auto &q : queries) {
            auto newV = abs(nums[q[1]] + q[0]);

            if (newV & 1) {
                if ((nums[q[1]] & 1) == 0) even -= nums[q[1]];
                nums[q[1]] += q[0];
            } else {
                if ((nums[q[1]] & 1) == 0) even -= nums[q[1]];
                nums[q[1]] += q[0];
                even += nums[q[1]];
            }

            res.emplace_back(even);
        }

        return res;
    }
};