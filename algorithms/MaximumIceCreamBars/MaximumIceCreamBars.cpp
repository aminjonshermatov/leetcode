#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (int i = 0; i < costs.size() && coins > 0; ++i) {
            if (costs[i] > coins) break;
            coins -= costs[i];
            ++ans;
        }
        return ans;
    }
};