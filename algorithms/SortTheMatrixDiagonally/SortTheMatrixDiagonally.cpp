#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int N(mat.size());
        const int M(mat[0].size());

        vector<vector<int>> res(N, vector<int>(M));
        for (int k = 0; k < N + M - 1; ++k) {
            int i = 0, j = 0;
            if (k < N) i = N - k - 1;
            else j = k - N + 1;

            multiset<int> ss;
            for (int ii = i, jj = j; ii < N && jj < M; ++ii, ++jj) ss.insert(mat[ii][jj]);

            for (auto it : ss) res[i++][j++] = it;
        }

        return res;
    }
};