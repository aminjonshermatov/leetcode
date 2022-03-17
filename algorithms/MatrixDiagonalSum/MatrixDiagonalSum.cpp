#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        const int n = static_cast<int>(mat.size());

        auto sum{0};

        for (int i = 0; i < n; ++i) sum += mat[i][i] + mat[i][n - i - 1];

        if (n & 1) sum -= mat[n >> 1][n >> 1];

        return sum;
    }
};