#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& A) {
        const int N(A.size());
        const int M(A[0].size());

        vector<set<int>> B(M + N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (B[N + j - i].empty()) B[N + j - i].insert(A[i][j]);
                else if (B[N + j - i].count(A[i][j]) == 0) return false;
            }
        }

        return true;
    }
};