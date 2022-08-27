#include "bits/stdc++.h"

using namespace std;

class Solution {
    int pref[101][101] = {0};
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int N(matrix.size());
        const int M(matrix[0].size());

        pref[0][0] = matrix[0][0];
        for (int i = 1; i < N; ++i) pref[i][0] = pref[i - 1][0] + matrix[i][0];
        for (int j = 1; j < M; ++j) pref[0][j] = pref[0][j - 1] + matrix[0][j];

        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < M; ++j) {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + matrix[i][j];
            }
        }

        int ans = INT_MIN;
        for (int si = 0; si < N; ++si) {
            for (int sj = 0; sj < M; ++sj) {
                for (int ei = si; ei < N; ++ei) {
                    for (int ej = sj; ej < M; ++ej) {
                        auto cur = pref[ei][ej];
                        if (si > 0) cur -= pref[si - 1][ej];
                        if (sj > 0) cur -= pref[ei][sj - 1];
                        if (si > 0 && sj > 0) cur += pref[si - 1][sj - 1];
                        if (cur <= k) ans = max(ans, cur);
                    }
                }
            }
        }

        return ans;
    }
};