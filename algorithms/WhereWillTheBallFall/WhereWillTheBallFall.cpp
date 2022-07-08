#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int n(grid.size());
        const int m(grid[0].size());

        vector<int> res(m);
        iota(res.begin(), res.end(), 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (res[j] == -1) continue;

                if (grid[i][res[j]] == 1) {
                    if (res[j] + 1 < m && grid[i][res[j] + 1] == -1 || res[j] + 1 == m) {
                        res[j] = -1;
                        continue;
                    }
                } else if (grid[i][res[j]] == -1) {
                    if (res[j] > 0 && grid[i][res[j] - 1] == 1 || res[j] == 0) {
                        res[j] = -1;
                        continue;
                    }
                }
                res[j] += grid[i][res[j]];

            }
        }

        return res;
    }
};