#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = static_cast<int>(matrix.size());
        const int m = static_cast<int>(matrix[0].size());

        if (target < matrix[0][0] or target > matrix[n - 1][m - 1]) return false;

        int row = 0, col = m - 1;

        while (row < n and col >= 0) {
            if (matrix[row][col] < target) ++row;
            else if (matrix[row][col] > target) --col;
            else return true;
        }

        return false;
    }
};