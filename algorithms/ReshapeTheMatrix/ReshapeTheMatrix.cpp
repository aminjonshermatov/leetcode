#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        const int n = static_cast<int>(mat.size());
        const int m = static_cast<int>(mat[0].size());

        if (n * m != r * c) return mat;

        auto x{0};
        auto y{0};
        vector<vector<int>> res(r, vector<int>(c));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[y][x++] = mat[i][j];

                if (x >= c) ++y, x = 0;
            }
        }

        return res;
    }
};