#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));

        for (int lt = 0, rb = n - 1, k = 1; lt <= rb; ++lt, --rb) {
            for (int j = lt; j <= rb; ++j) mat[lt][j] = k++;
            for (int i = lt + 1; i < rb; ++i) mat[i][rb] = k++;
            if (lt == rb) break;
            for (int j = rb; j >= lt; --j) mat[rb][j] = k++;
            for (int i = rb - 1; i > lt; --i) mat[i][lt] = k++;
        }

        return mat;
    }
};