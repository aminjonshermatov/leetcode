#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>&& prices) {
        int maxProf = 0;

        size_t len = prices.size();
        for (size_t i = 0; i < len; ++i) {
            if (i + 1 == len) break;

            if (prices[i] < prices[i + 1]) {
                size_t j = i + 1;

                while (j < len && prices[j] > prices[i]) {
                    maxProf = max(maxProf, prices[j++] - prices[i]);
                }
            }
        }

        return maxProf;
    }
};