#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(),
                n = mat[0].size();

        if (m * n != r * c) return mat;

        vector<vector<int>> res(r, vector<int>(c));

        int i = 0, j = 0;

        for (int ii = 0; ii < m; ++ii) {
            for (int jj = 0; jj < n; ++jj) {
                res[i][j++] = mat[ii][jj];

                if (j == c) {
                    j = 0;
                    ++i;
                }
            }
        }

        return res;
    }
};