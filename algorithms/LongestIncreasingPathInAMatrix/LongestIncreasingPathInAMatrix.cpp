#include "bits/stdc++.h"

using namespace std;

class Solution {
    static constexpr int dir[5] = {0, 1, 0, -1, 0};
    int dp[201][201];

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int n(matrix.size());
        const int m(matrix[0].size());

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0 || i >= n || j < 0 || j >= m) return 0;

            if (dp[i][j] != -1) return dp[i][j];

            int ans = 1;
            for (int k = 0; k < 4; ++k) {
                int ii = i + dir[k];
                int jj = j + dir[k + 1];

                if (ii < 0 || ii >= n || jj < 0 || jj >= m || matrix[ii][jj] <= matrix[i][j]) continue;
                ans = max(ans, 1 + dfs(ii, jj));
            }

            return dp[i][j] = ans;
        };

        memset(dp, -1, sizeof(dp));

        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }

        return ans;
    }
};