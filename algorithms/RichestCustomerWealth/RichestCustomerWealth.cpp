#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxW{0};

        for (const auto &banks : accounts)
            maxW = max(maxW, accumulate(banks.begin(), banks.end(), 0));

        return maxW;
    }
};