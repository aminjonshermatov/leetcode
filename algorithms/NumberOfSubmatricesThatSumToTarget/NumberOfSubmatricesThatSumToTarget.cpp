#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        const int n(mat.size());
        const int m(mat[0].size());

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[1][1] = mat[0][0];
        for (int i = 2, j = 1; i <= n; ++i) dp[i][j] += dp[i - 1][j] + mat[i - 1][j - 1];
        for (int i = 1, j = 2; j <= m; ++j) dp[i][j] += dp[i][j - 1] + mat[i - 1][j - 1];

        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= m; ++j) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        int ans = 0;
        for (int y1 = 1; y1 <= n; ++y1) {
            for (int x1 = 1; x1 <= m; ++x1) {
                for (int y2 = y1; y2 <= n; ++y2) {
                    for (int x2 = x1; x2 <= m; ++x2) {
                        if (dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1] == target) {
                            ++ans;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
