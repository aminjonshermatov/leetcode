#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs) -> bool { return lhs[0] < rhs[0]; });
        const int n = static_cast<int>(intervals.size());
        int k = 0;
        for (int i = 0; i < n; ++i) {
            auto end = intervals[i][1];

            while (i + 1 < n and intervals[i + 1][0] < end) {
                if (intervals[i + 1][1] < end) {
                    end = intervals[i + 1][1];
                    intervals[i][0] = intervals[i][1] = INT_MAX;
                } else {
                    intervals[i + 1][0] = intervals[i + 1][1] = INT_MAX;
                }
                ++i;
                ++k;
            }
        }

        return k;
    }
};