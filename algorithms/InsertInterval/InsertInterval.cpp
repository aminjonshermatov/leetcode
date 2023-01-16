#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        sort(intervals.begin(), intervals.end());
        const int n(intervals.size());

        vector<vector<int>> res;
        res.reserve(n);
        for (int i = 0; i < n; ++i) {
            auto start = intervals[i][0];
            auto end = intervals[i][1];
            while (i + 1 < n && intervals[i + 1][0] <= end) end = max(end, intervals[++i][1]);
            res.push_back({start, end});
        }

        return res;
    }
};