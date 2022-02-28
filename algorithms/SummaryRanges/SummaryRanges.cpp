#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        const int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            auto l{nums[i]};
            auto r{nums[i]};

            while (i + 1 < n and nums[i + 1] == r + 1) r = nums[++i];

            if (l == r) res.push_back(to_string(l));
            else res.push_back(to_string(l) + "->" + to_string(r));
        }

        return res;
    }
};