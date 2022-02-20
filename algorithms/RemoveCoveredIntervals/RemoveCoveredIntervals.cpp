#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs) -> bool {
            if (lhs[0] != rhs[0]) return lhs[0] < rhs[0];
            return lhs[1] > rhs[1];
        });

        const int n = static_cast<int>(intervals.size());
        int res = 0;

        for (int i = 0; i < n; ++i) {
            int end = intervals[i][1];
            while (i + 1 < n and intervals[i + 1][1] <= end) ++i;
            ++res;
        }

        return res;
    }
};