#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int n = static_cast<int>(grid.size());
        const int m = static_cast<int>(grid[0].size());

        deque<int> dq;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dq.push_back(grid[i][j]);
            }
        }

        k %= m * n;

        if (k == 0) return grid;

        while (k--) {
            dq.push_front(dq.back());
            dq.pop_back();
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = dq.front();
                dq.pop_front();
            }
        }

        return grid;
    }
};