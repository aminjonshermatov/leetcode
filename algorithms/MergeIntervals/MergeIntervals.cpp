#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int n = static_cast<int>(intervals.size());

        sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs) -> bool {
            if (lhs[0] == rhs[0]) return lhs[0] < rhs[0];
            return lhs[0] < rhs[0];
        });

        vector<vector<int>> res;

        for (int i = 0; i < n; ++i) {
            auto s{intervals[i][0]};
            auto e{intervals[i][1]};

            while (i + 1 < n and intervals[i + 1][0] <= e) {
                e = max(e, intervals[i + 1][1]);
                ++i;
            }

            res.push_back({s, e});
        }

        return res;
    }
};