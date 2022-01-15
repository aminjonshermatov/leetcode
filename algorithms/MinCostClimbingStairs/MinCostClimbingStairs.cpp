#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if (size == 2) return min(cost[0], cost[1]);

        vector<int> minCost(size);

        for (int i = 0; i < size; ++i) minCost[i] = cost[i];

        for (int i = size - 3; i >= 0; --i) {
            minCost[i] += min(minCost[i + 1], minCost[i + 2]);
        }

        return min(minCost[0], minCost[1]);
    }
};