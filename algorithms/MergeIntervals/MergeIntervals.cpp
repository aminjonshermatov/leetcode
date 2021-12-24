#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        stack<pair<int, int>> st;

        sort(intervals.begin(), intervals.end(), [&](auto &l, auto &r) -> bool { return l[0] < r[0]; });
        for (const auto& p : intervals) {
            int start = p[0], end = p[1];

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

        while (!st.empty()) {
            auto [s, e] = st.top();
            res.push_back({s, e});
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};