#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& S, vector<int>& A) {
        const int n(S.size());
        vector<pair<int, int>> AS(n);
        for (int i = 0; i < n; ++i) AS[i] = pair(A[i], S[i]);
        sort(AS.begin(), AS.end(), greater<>());

        int ans = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            auto [_, s] = AS[i];
            dp[i] = s;
            for (int j = 0; j < i; ++j) if (AS[j].second >= AS[i].second) dp[i] = max(dp[i], dp[j] + s);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};