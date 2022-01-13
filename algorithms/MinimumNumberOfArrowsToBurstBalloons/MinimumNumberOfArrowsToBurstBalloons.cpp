#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](auto &lhs, auto &rhs) -> bool { return lhs[0] < rhs[0]; });

        int minCount = 0;
        int i = 0;
        while (i < points.size()) {
            int j = i + 1;
            auto end{points[i][1]};
            while (j < points.size() && points[j][0] <= end) {
                end = min(end, points[j][1]);
                ++j;
            }

            i = j;
            ++minCount;
        }

        return minCount;
    }
};