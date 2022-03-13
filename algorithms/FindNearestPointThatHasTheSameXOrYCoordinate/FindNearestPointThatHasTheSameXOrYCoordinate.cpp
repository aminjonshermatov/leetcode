#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        const int n = static_cast<int>(points.size());
        int smallest = INT_MAX, idx = -1;
        for (int i = 0; i < n; ++i) {
            if (points[i][0] == x or points[i][1] == y) {
                auto  dist{abs(x - points[i][0]) + abs(y - points[i][1])};
                if (dist < smallest) {
                    idx = i;
                    smallest = dist;
                }
            }
        }

        return idx;
    }
};