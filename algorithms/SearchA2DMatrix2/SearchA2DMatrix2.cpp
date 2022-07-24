#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        const int n(mat.size());
        const int m(mat[0].size());

        for (int i = 0, j = m - 1; i < n && j >= 0;) {
            if (mat[i][j] > target) --j;
            else if (mat[i][j] < target) ++i;
            else return true;
        }

        return false;
    }
};
