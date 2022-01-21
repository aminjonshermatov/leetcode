#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0)< accumulate(cost.begin(), cost.end(), 0)) return -1;

        auto total{0};
        auto res{0};

        for (size_t i{0}; i < gas.size(); ++i) {
            total += gas[i] - cost[i];

            if (total < 0) {
                total = 0;
                res = i + 1;
            }
        }

        return res;
    }
};