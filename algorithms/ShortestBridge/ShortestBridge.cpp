#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int n = static_cast<int>(grid.size());

        vector<pair<int, int>> f, s;

        const function<void(const int, const int)> dfs = [&](const int i, const int j) -> void {
            grid[i][j] = 2;
            s.emplace_back(i, j);

            if (i - 1 >= 0 and grid[i - 1][j] == 1) dfs(i - 1, j);
            if (j + 1 < n and grid[i][j + 1] == 1) dfs(i, j + 1);
            if (i + 1 < n and grid[i + 1][j] == 1) dfs(i + 1, j);
            if (j - 1 >= 0 and grid[i][j - 1] == 1) dfs(i, j - 1);
        };

        bool found = false;
        for (int i = 0; i < n and not found; ++i) {
            for (int j = 0; j < n and not found; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    found = true;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) f.emplace_back(i, j);
            }
        }

        int res = INT_MAX;
        for (const auto [fi, fj] : f) {
            for (const auto [si, sj] : s) {
                res = min(res, abs(fi - si) + abs(fj - sj) - 1);
            }
        }

        return res;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        const int n = static_cast<int>(grid.size());
        queue<pair<int, int>> q;

        const function<void(const int, const int)> dfs = [&](const int i, const int j) -> void {
            if (i < 0 or i >= n or j < 0 or j >= n or grid[i][j] != 1) return;

            grid[i][j] = 2;
            q.push({i, j});
            dfs(i - 1, j);
            dfs(i + 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };

        bool found = false;
        for (int i = 0; i < n and not found; ++i) {
            for (int j = 0; j < n and not found; ++j) {
                if (grid[i][j] == 1) {
                    found = true;
                    dfs(i, j);
                }
            }
        }

        int res = 0;
        while (not q.empty()) {
            int sz = static_cast<int>(q.size());

            while (sz-- > 0) {
                auto [i, j] = q.front(); q.pop();

                if (i - 1 >= 0 and grid[i - 1][j] != 2) {
                    if (grid[i - 1][j] == 1) return res;
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                }
                if (i + 1 < n and grid[i + 1][j] != 2) {
                    if (grid[i + 1][j] == 1) return res;
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }

                if (j - 1 >= 0 and grid[i][j - 1] != 2) {
                    if (grid[i][j - 1] == 1) return res;
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                }
                if (j + 1 < n and grid[i][j + 1] != 2) {
                    if (grid[i][j + 1] == 1) return res;
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
            }

            ++res;
        }

        return {};
    }
};