#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0) return 0;
        const int n = 100;

        vector<vector<double>> dp(n, vector<double>(n));
        dp[0][0] = static_cast<double>(poured);

        for (int r = 0; r <= query_row; ++r) {
            for (int c = 0; c <= query_glass; ++c) {
                if (dp[r][c] > 1) {
                    auto rem{dp[r][c] - 1.0};

                    if (r + 1 < n) {
                        dp[r + 1][c] += rem / 2;
                        dp[r + 1][c + 1] += rem / 2;
                    }
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};