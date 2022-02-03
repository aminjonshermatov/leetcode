#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int   r = static_cast<int>(grid.size()),
                    c = static_cast<int>(grid[0].size());

        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<int, int>> q;

        if (grid[0][0] == 0) {
            q.push({0, 0});
            visited[0][0] = true;
        }

        int path = 1;

        while (not q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [y, x] = q.front(); q.pop();
                if (y == r - 1 and x == c - 1) return path;

                if (y - 1 >= 0 and not visited[y - 1][x] and grid[y - 1][x] == 0) {
                    q.push({y - 1, x});
                    visited[y - 1][x] = true;
                }
                if (y - 1 >= 0 and x + 1 < c and not visited[y - 1][x + 1] and grid[y - 1][x + 1] == 0) {
                    q.push({y - 1, x + 1});
                    visited[y - 1][x + 1] = true;
                }
                if (x + 1 < c and not visited[y][x + 1] and grid[y][x + 1] == 0) {
                    q.push({y, x + 1});
                    visited[y][x + 1] = true;
                }
                if (y + 1 < r and x + 1 < c and not visited[y + 1][x + 1] and grid[y + 1][x + 1] == 0) {
                    q.push({y + 1, x + 1});
                    visited[y + 1][x + 1] = true;
                }
                if (y + 1 < r and not visited[y + 1][x] and grid[y + 1][x] == 0) {
                    q.push({y + 1, x});
                    visited[y + 1][x] = true;
                }
                if (y + 1 < r and x - 1 >= 0 and not visited[y + 1][x - 1] and grid[y + 1][x - 1] == 0) {
                    q.push({y + 1, x - 1});
                    visited[y + 1][x - 1] = true;
                }
                if (x - 1 >= 0 and not visited[y][x - 1] and grid[y][x - 1] == 0) {
                    q.push({y, x - 1});
                    visited[y][x - 1] = true;
                }
                if (y - 1 >= 0 and x - 1 >= 0 and not visited[y - 1][x - 1] and grid[y - 1][x - 1] == 0) {
                    q.push({y - 1, x - 1});
                    visited[y - 1][x - 1] = true;
                }
            }

            ++path;
        }

        return -1;
    }
};