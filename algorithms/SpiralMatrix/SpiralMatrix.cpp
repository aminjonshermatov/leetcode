#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0,
            right = matrix[0].size(),
            top = 0,
            bottom = matrix.size();

        vector<int> ans;

        while (left < right && top < bottom) {
            // left -> right
            for (int i = left; i < right; ++i) ans.push_back(matrix[top][i]);
            ++top;

            // top -> bottom
            for (int i = top; i < bottom; ++i) ans.push_back(matrix[i][right - 1]);
            --right;

            if (left >= right || top >= bottom) break;

            // right -> left
            for (int i = right - 1; i >= left; --i) ans.push_back(matrix[bottom - 1][i]);
            --bottom;

            // bottom -> top
            for (int i = bottom - 1; i >= top; --i) ans.push_back(matrix[i][left]);
            ++left;
        }

        return ans;
    }
};