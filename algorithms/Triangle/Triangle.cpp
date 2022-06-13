#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), 0));

        for (int l = 0; l < triangle.size(); ++l) {
            for (int idx = 0; idx < triangle[l].size(); ++idx) {
                dp[l][idx] = triangle[l][idx];
            }
        }

        for (int l = triangle.size() - 2; l >= 0; --l) {
            for (int idx = 0; idx < triangle[l].size(); ++idx) {
                dp[l][idx] += min(dp[l + 1][idx], dp[l + 1][idx + 1]);
            }
        }

        return dp[0][0];
    }
};

class Solution {
    int dp[201][201];
public:
    int minimumTotal(vector<vector<int>>& tr) {
        int n(tr.size());

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
        }

        const function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i >= n || j > i) return 0;
            if (dp[i][j] != -1) return dp[i][j];

            return dp[i][j] = min(dfs(i + 1, j), dfs(i + 1, j + 1)) + tr[i][j];
        };

        return dfs(0, 0);
    }
};