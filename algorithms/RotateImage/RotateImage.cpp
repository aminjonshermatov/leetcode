#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int leftTop = 0,
            rightBottom = matrix.size();

        while (leftTop < rightBottom) {
            for (int i = leftTop; i < rightBottom - 1; ++i) {
                tie(
                        matrix[leftTop][i],
                        matrix[i][rightBottom - 1],
                        matrix[rightBottom - 1][leftTop + rightBottom - 1 - i],
                        matrix[leftTop + rightBottom - 1 - i][leftTop]
                ) = make_tuple(
                        matrix[leftTop + rightBottom - 1 - i][leftTop],
                        matrix[leftTop][i],
                        matrix[i][rightBottom - 1],
                        matrix[rightBottom - 1][leftTop + rightBottom - 1 - i]
                );
            }

            ++leftTop;
            --rightBottom;
        }
    }
};