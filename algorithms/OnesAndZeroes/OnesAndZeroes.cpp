#include "bits/stdc++.h"

using namespace std;

class Solution {
    int dp[601][101][101];

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<array<int, 2>> f(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            f[i][0] = count(strs[i].begin(), strs[i].end(), '0');
            f[i][1] = strs[i].size() - f[i][0];
        }

        function<int(int, int, int)> dfs = [&](int idx, int z, int o) -> int {
            if (idx >= f.size()) return 0;
            if (dp[idx][z][o] != -1) return dp[idx][z][o];

            int ans = dfs(idx + 1, z, o);
            if (z - f[idx][0] >= 0 && o - f[idx][1] >= 0) {
                ans = max(ans, 1 + dfs(idx + 1, z - f[idx][0], o - f[idx][1]));
            }

            return dp[idx][z][o] = ans;
        };

        memset(dp, -1, sizeof(dp));

        return dfs(0, m, n);
    }
};