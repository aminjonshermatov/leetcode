#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(),
            c = grid[0].size();

        int freshCnt = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) ++freshCnt;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        int ans = -1;

        array<int, 4> dx = {1, -1, 0, 0};
        array<int, 4> dy = {0, 0, 1, -1};
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [y, x] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int xx = x + dx[i],
                        yy = y + dy[i];

                    if (xx < 0 || xx >= c || yy < 0 || yy >= r || grid[yy][xx] != 1) continue;

                    grid[yy][xx] = 2;
                    q.push({yy, xx});
                    --freshCnt;
                }
            }

            ++ans;
        }

        if (freshCnt != 0) return -1;
        return ans == -1 ? 0 : ans;
    }
};