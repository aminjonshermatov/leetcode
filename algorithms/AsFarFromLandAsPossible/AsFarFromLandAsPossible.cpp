#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int r = static_cast<int>(grid.size());
        const int c = static_cast<int>(grid[0].size());

        vector<vector<int>> dp(r, vector<int>(c, INT_MAX));
        bool all0 = true, all1 = true;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    all0 = false;
                    dp[i][j] = 0;
                } else {
                    all1 = false;
                }
            }
        }

        if (all1 or all0) return -1;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) continue;

                if (j - 1 >= 0 and dp[i][j - 1] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                if (i - 1 >= 0 and dp[i - 1][j] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
        }

        int res = -1;
        for (int i = r - 1; i >= 0; --i) {
            for (int j = c - 1; j >= 0; --j) {
                if (grid[i][j] == 1) continue;

                if (j + 1 < c and dp[i][j + 1] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                if (i + 1 < r and dp[i + 1][j] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);

                if (dp[i][j] != INT_MAX) res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};