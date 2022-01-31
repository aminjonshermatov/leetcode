#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;

        for (const auto &account : accounts) {
            maxWealth = max(maxWealth, accumulate(account.begin(), account.end(), 0));
        }

        return maxWealth;
    }
};