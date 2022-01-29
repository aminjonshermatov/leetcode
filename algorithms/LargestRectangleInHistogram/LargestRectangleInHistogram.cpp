#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = static_cast<int>(heights.size());
        int maxArea = 0;
        // <start-index, height>
        stack<pair<int, int>> st;

        for (int i = 0; i < n; ++i) {
            auto start = i;

            while (not st.empty() and st.top().second > heights[i]) {
                auto [idx, height] = st.top(); st.pop();

                maxArea = max(maxArea, (i - idx) * height);
                start = idx;
            }

            st.push({start, heights[i]});
        }

        while (not st.empty()) {
            auto [idx, height] = st.top(); st.pop();
            maxArea = max(maxArea, (n - idx) * height);
        }

        return maxArea;
    }
};