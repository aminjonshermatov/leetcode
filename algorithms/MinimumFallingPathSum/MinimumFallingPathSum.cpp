#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev(matrix[0]), cur(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cur[j] = prev[j];

                if (j > 0) cur[j] = min(cur[j], prev[j - 1]);
                if (j + 1 < n) cur[j] = min(cur[j], prev[j + 1]);

                cur[j] += matrix[i][j];
            }

            prev = cur;
        }

        return *min_element(prev.begin(), prev.end());
    }
};