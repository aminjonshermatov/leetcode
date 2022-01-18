#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
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
};