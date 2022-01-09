#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size(),
            c = mat[0].size();

        vector<vector<int>> dis(r, vector<int>(c, INT_MAX - 1e5));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (mat[i][j] == 0) dis[i][j] = 0;
                else {
                    if (i > 0) dis[i][j] = min(dis[i][j], dis[i - 1][j] + 1);
                    if (j > 0) dis[i][j] = min(dis[i][j], dis[i][j - 1] + 1);
                }
            }
        }

        for (int i = r -1; i >= 0; --i) {
            for (int j = c - 1; j >= 0; --j) {
                if (i < r - 1) dis[i][j] = min(dis[i][j], dis[i + 1][j] + 1);
                if (j < c - 1) dis[i][j] = min(dis[i][j], dis[i][j + 1] + 1);
            }
        }

        return dis;
    }
};