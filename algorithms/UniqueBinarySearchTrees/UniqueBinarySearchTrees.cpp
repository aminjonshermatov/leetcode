#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 1);

        for (int i = 2; i <= n; ++i) {
            int total = 0;

            for (int j = 1; j <= i; ++j) {
                total += dp[j - 1] * dp[i - j];
            }
            dp[i] = total;
        }

        return dp[n];
    }
};