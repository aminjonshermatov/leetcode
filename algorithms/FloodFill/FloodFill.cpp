#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        const int n(image.size());
        const int m(image[0].size());

        queue<pair<int, int>> q;

        q.push({sr, sc});
        int srcColor = image[sr][sc];
        image[sr][sc] = -1;
        array<int, 5> dk = {1, 0, -1, 0, 1};
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            for (int k = 0; k < 4; ++k) {
                int ii = i + dk[k], jj = j + dk[k + 1];

                if (ii >= 0 && ii < n && jj >= 0 && jj < m && image[ii][jj] == srcColor) {
                    image[ii][jj] = -1;
                    q.push({ii, jj});
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (image[i][j] < 0) image[i][j] = color;
            }
        }

        return image;
    }
};