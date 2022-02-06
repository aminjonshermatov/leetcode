#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int leftTop = 0, rightBottom = n - 1, curN = 0;

        while (leftTop <= rightBottom) {
            // left to right
            for (int j = leftTop; j <= rightBottom; ++j) matrix[leftTop][j] = ++curN;

            // top to bottom
            for (int i = leftTop + 1; i <= rightBottom; ++i) matrix[i][rightBottom] = ++curN;

            // right to left
            for (int j = rightBottom - 1; j >= leftTop; --j) matrix[rightBottom][j] = ++curN;

            // bottom to top
            for (int i = rightBottom - 1; i > leftTop; --i) matrix[i][leftTop] = ++curN;

            ++leftTop;
            --rightBottom;
        }

        return matrix;
    }
};
