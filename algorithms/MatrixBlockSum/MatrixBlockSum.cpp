#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int r = static_cast<int>(mat.size()),
            c = static_cast<int>(mat[0].size());

        vector<vector<int>> prefix(r, vector<int>(c)), res(r, vector<int>(c));

        for (int i = 0; i < r; ++i) prefix[i][0] = mat[i][0];

        for (int i = 0; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                prefix[i][j] = prefix[i][j - 1] + mat[i][j];
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int m = max(0, i - k); m <= min(r - 1, i + k); ++m) {
                    res[i][j] += prefix[m][min(c - 1, j + k)];

                    if (j - k - 1 >= 0) res[i][j] -= prefix[m][j - k - 1];
                }
            }
        }

        return res;
    }
};