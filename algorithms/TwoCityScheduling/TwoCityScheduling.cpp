#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),
             costs.end(),
             [](const auto &lhs, const auto &rhs) {
                 return lhs[1] - lhs[0] < rhs[1] - rhs[0];
             });

        const int n = static_cast<int>(costs.size());

        auto res{0};

        for (int i = 0; i < n; ++i) {
            if (i < (n >> 1)) res += costs[i][1];
            else res += costs[i][0];
        }

        return res;
    }
};