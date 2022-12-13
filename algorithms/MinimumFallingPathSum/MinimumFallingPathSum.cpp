#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int n(A.size());
        const int m(A[0].size());

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int mn = A[i - 1][j];
                if (j > 0) mn = min(mn, A[i - 1][j - 1]);
                if (j + 1 < m) mn = min(mn, A[i - 1][j + 1]);
                A[i][j] += mn;
            }
        }

        return *min_element(A[n - 1].begin(), A[n - 1].end());
    }
};