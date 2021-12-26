#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [&](auto &l, auto &r) -> bool {
            return (l[0] * l[0] + l[1] * l[1]) < (r[0] * r[0] + r[1] * r[1]);
        });

        points.resize(k);
        return points;
    }
};