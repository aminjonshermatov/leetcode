#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        if (rows == 0) return 0;

        int cols = static_cast<int>(matrix[0].size());

        int maxArea = 0;
        vector<int> curRow(cols);
        stack<pair<int, int>> st;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '0') curRow[j] = 0;
                else curRow[j] += 1;

                int start = j;

                while (!st.empty() && st.top().second > curRow[j]) {
                    auto &[idx, height] = st.top();
                    st.pop();

                    maxArea = max(maxArea, height * (j - idx));
                    start = idx;
                }
                st.push({start, curRow[j]});
            }

            while (!st.empty()) {
                auto &[idx, height] = st.top();
                st.pop();

                maxArea = max(maxArea, height * (cols - idx));
            }
        }

        return maxArea;
    }
};