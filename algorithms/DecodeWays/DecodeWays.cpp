#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        const int N(s.size());

        vector<int> dp(N + 2, 0);
        dp[N] = 1;
        for (int i = N - 1; i >= 0; --i) {
            if (s[i] != '0') dp[i] += dp[i + 1];
            if (s[i] > '0' && s[i] < '2' || (s[i] == '2' && s[i + 1] <= '6')) dp[i] += dp[i + 2];
        }

        return dp[0];
    }
};