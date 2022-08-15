#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int N(grid.size());
        const int M(grid[0].size());

        array<int8_t, 3> dk = {-1, 0, 1};
        vector<vector<int>> res(N - 2, vector<int>(M - 2, 0));
        for (size_t i = 1; i + 1 < N; ++i) {
            for (size_t j = 1; j + 1 < M; ++j) {
                for (auto ii : dk) {
                    for (auto jj : dk) {
                        res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i + ii][j + jj]);
                    }
                }
            }
        }

        return res;
    }
};