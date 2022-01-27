#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // O(log(r + c)) - TC, O(1) - SC
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(),
            c = matrix[0].size();

        if (matrix[0][0] > target or matrix[r - 1][c - 1] < target) return false;

        int lo = 0, hi =r * c;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (matrix[mid / c][mid % c] < target) lo = mid + 1;
            else if (matrix[mid / c][mid % c] > target) hi = mid;
            else return true;
        }

        return false;
    }

    // O(log(r) + log(c)) - TC, O(1) - SC
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int   r = matrix.size(),
                    c = matrix[0].size();

        if (matrix[0][0] > target or matrix[r - 1][c - 1] < target) return false;

        int row_lo = 0, row_hi = r;

        while (row_lo < row_hi) {
            const auto row_mid = row_lo + ((row_hi - row_lo) >> 1);

            if (matrix[row_mid][0] > target)            row_hi = row_mid;
            else if (matrix[row_mid][c - 1] < target)   row_lo = row_mid + 1;
            else {
                int col_lo = 0, col_hi = c;

                while (col_lo < col_hi) {
                    const auto col_mid = col_lo + ((col_hi - col_lo) >> 1);

                    if (matrix[row_mid][col_mid] < target)      col_lo = col_mid + 1;
                    else if (matrix[row_mid][col_mid] > target) col_hi = col_mid;
                    else return true;
                }

                return false;
            }
        }

        return false;
    }
};