#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size(),
                cols = image[0].size();

        int color = image[sr][sc];

        function<void(int, int)> dfs = [&dfs, &image, &newColor, &rows, &cols, &color](int x, int y) -> void {
            image[y][x] = newColor;
            if (x >= 0 && x + 1 < cols && image[y][x + 1] == color) dfs(x + 1, y);
            if (x - 1 >= 0 && x < cols && image[y][x - 1] == color) dfs(x - 1, y);
            if (y >= 0 && y + 1 < rows && image[y + 1][x] == color) dfs(x, y + 1);
            if (y - 1 >= 0 && y < rows && image[y - 1][x] == color) dfs(x, y - 1);
        };

        if (color != newColor) dfs(sc, sr);

        return image;
    }
};