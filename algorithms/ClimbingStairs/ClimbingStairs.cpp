#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    int climbStairs(int n) {
        int prev = 1,
                cur = 1;

        for (int i = 2; i <= n; ++i) {
            auto temp{cur};
            cur += prev;
            prev = temp;
        }

        return cur;
    }
};
