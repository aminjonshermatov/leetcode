#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // todo: implement cache (level, idx) -> minSum
        // otherwise is should be TL
        function<int(int, int)> dfs = [&](int level, int idx) -> int {
            if (level >= triangle.size() || idx >= triangle[level].size()) return 0;

            return triangle[level][idx] + min(dfs(level + 1, idx), dfs(level + 1, idx + 1));
        };

        return dfs(0, 0);
    }

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