#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &lhs, auto &rhs) {
            return lhs[1] > rhs[1];
        });

        const int n(boxTypes.size());

        int ans = 0;
        for (const auto it : boxTypes) {
            int taken = min(truckSize, it[0]);
            truckSize -= taken;
            ans += taken * it[1];
        }

        return ans;
    }
};