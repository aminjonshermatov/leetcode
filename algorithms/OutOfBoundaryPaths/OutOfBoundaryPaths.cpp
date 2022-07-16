#include "bits/stdc++.h"

using namespace std;

class Solution {
    static constexpr int MOD = 1e9 + 7;
    int memo[51][51][51];

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        array<int, 5> dk = {-1, 0, 1, 0, -1};

        const function<int(int, int, int)> dfs = [&](int i, int j, int N) {
            if (i < 0 || i >= m || j < 0 || j >= n) return 1;
            if (N <= 0) return 0;
            if (memo[i][j][N] != -1) return memo[i][j][N];

            int temp = 0;
            for (int k = 0; k < 4; ++k) {
                temp += dfs(i + dk[k], j + dk[k + 1], N - 1);
                temp %= MOD;
            }

            return memo[i][j][N] = temp;
        };

        memset(memo, -1, sizeof(memo));

        return dfs(startRow, startColumn, maxMove);
    }
};
