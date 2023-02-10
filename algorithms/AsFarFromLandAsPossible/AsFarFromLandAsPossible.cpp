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

class Solution {
    static inline constexpr auto  inf = numeric_limits<int>::max();
    static inline constexpr auto ninf = numeric_limits<int>::min();
    static inline constexpr array<int, 5> dk{1,0,-1,0,1};
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int n(grid.size());
        const auto is_safe = [&](int i, int j) { return clamp(i, 0, n - 1) == i && clamp(j, 0, n - 1) == j; };

        queue<tuple<int, int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, inf));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) q.emplace(i, j, 0), dist[i][j] = 0;
            }
        }

        if (q.empty()) return -1;
        while (!q.empty()) {
            auto [i, j, d] = q.front(); q.pop();
            if (dist[i][j] < d) continue;

            for (int k = 0; k < 4; ++k) {
                auto ni = i + dk[k];
                auto nj = j + dk[k + 1];
                if (is_safe(ni, nj) && grid[ni][nj] == 0 && dist[ni][nj] > dist[i][j] + 1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj, dist[ni][nj]);
                }
            }
        }

        int ans = ninf;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && dist[i][j] != inf) ans = max(ans, dist[i][j]);
            }
        }
        return ans == ninf ? -1 : ans;
    }
};