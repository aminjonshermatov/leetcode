#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<pair<int, int>> st;

        sort(intervals.begin(), intervals.end(), [&](auto &l, auto &r) -> bool { return l[0] < r[0]; });
        for (const auto& interval : intervals) {
            int start = interval[0], end = interval[1];

            if (st.empty()) {
                st.push({start, end});
                continue;
            }

            while (!st.empty() && st.top().second >= start) {
                auto [ss, ee] = st.top();
                start  = ss;
                end = max(end, ee);
                st.pop();
            }

            st.push({start, end});
        }

        vector<vector<int>> res;
        while (!st.empty()) {
            auto [s, e] = st.top();
            res.push_back({s, e});
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};