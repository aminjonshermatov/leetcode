#include "bits/stdc++.h"

using namespace std;

class Solution {
    static inline constexpr array<int, 5> dk = {1, 0, -1, 0, 1};
    static inline constexpr int inf = numeric_limits<int>::max();

public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        const int N(grid.size());
        const int M(grid[0].size());

        auto isSafe = [&](int y, int x) -> bool {
            return y >= 0 && y < N && x >= 0 && x < M;
        };

        queue<tuple<int, int, int, int>> q;
        vector<vector<vector<bool>>> used(N, vector<vector<bool>>(M, vector<bool>(K + 1, false)));
        q.emplace(0, 0, K, 0);
        used[0][0][K] = true;

        int ans = inf;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int y = get<0>(cur), x = get<1>(cur), k = get<2>(cur), s = get<3>(cur);
            if (y == N - 1 && x == M - 1) return s;

            for (int i = 0; i < 4; ++i) {
                int yy = y + dk[i], xx = x + dk[i + 1];
                if (!isSafe(yy, xx)) continue;

                if (grid[yy][xx] == 0 && !used[yy][xx][k]) {
                    used[yy][xx][k] = true;
                    q.emplace(yy, xx, k, s + 1);
                } else if (k > 0 && !used[yy][xx][k - 1]) {
                    used[yy][xx][k - 1] = true;
                    q.emplace(yy, xx, k - 1, s + 1);
                }
            }
        }

        return -1;
    }
};