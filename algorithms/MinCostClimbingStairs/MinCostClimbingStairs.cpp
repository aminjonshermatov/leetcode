#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n(cost.size());

        vector<int> mn(cost);
        for (int i = n - 3; i >= 0; --i) mn[i] += min(mn[i + 1], mn[i + 2]);

        return min(mn[0], mn[1]);
    }
};