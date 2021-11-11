#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // O(m*n) - TC, O(m + n) - SC
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        bool isCol = false, isRow = false;

        for (int i = 0; i < c; ++i) {
            if (matrix[0][i] == 0) {
                isRow = true;
            }
        }

        for (int i = 0; i < r; ++i) {
            if (matrix[i][0] == 0) {
                isCol = true;
            }
        }


        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (isCol) {
            for (int i = 0; i < r; ++i) {
                matrix[i][0] = 0;
            }
        }

        if (isRow) {
            for (int i = 0; i < c; ++i) {
                matrix[0][i] = 0;
            }
        }
    }

    // O(m*n) - TC, O(1) - SC
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (const int r : row) {
            for (int i = 0; i < matrix[r].size(); ++i) {
                matrix[r][i] = 0;
            }
        }

        for (const int c : col) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][c] = 0;
            }
        }
    }
};