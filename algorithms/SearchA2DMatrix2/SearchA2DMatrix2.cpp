#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = (int)matrix.size();
        const int m = (int)matrix[0].size();

        int i = 0, j = m - 1;

        while (i >= 0 && i < n && j >= 0 && j < m) {
            if (matrix[i][j] < target) ++i;
            else if (matrix[i][j] > target) --j;
            else return true;
        }

        return false;
    }
};