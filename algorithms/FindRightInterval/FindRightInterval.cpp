#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp_;

        for (int i = 0; i < intervals.size(); ++i) {
            mp_[intervals[i][0]] = i;
        }

        vector<int> ans;
        ans.reserve(intervals.size());
        for (const auto i : intervals) {
            auto lo = mp_.lower_bound(i[1]);
            ans.push_back(lo == mp_.end() ? -1 : lo->second);
        }

        return ans;
    }
};