#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int   w1s = static_cast<int>(word1.size()),
                w2s = static_cast<int>(word2.size());

        vector<vector<int>> dp(w1s + 1, vector<int>(w2s + 1));

        for (int i = 1; i <= w1s; ++i) dp[i][0] = i;
        for (int j = 1; j <= w2s; ++j) dp[0][j] = j;

        for (int i = 1; i <= w1s; ++i) {
            for (int j = 1; j <= w2s; ++j) {
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + static_cast<int>(word1[i - 1] != word2[j - 1])});
            }
        }

        return dp[w1s][w2s];
    }
};