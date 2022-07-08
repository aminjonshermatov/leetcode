#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        const int n(mat.size());
        const int m(mat[0].size());

        vector<int> res;
        res.reserve(n * m);
        for (int il = 0, jl = 0, ih = n - 1, jh = m - 1;
            il <= ih && jl <= jh;
            ++il, ++jl, --ih, --jh) {

            for (int jj = jl; jj <= jh; ++jj)       res.push_back(mat[il][jj]);
            for (int ii = il + 1; ii <= ih; ++ii)   res.push_back(mat[ii][jh]);
            if (il == ih || jl == jh) break;
            for (int jj = jh - 1; jj >= jl; --jj)   res.push_back(mat[ih][jj]);
            for (int ii = ih - 1; ii > il; --ii)    res.push_back(mat[ii][jl]);
        }

        return res;
    }
};