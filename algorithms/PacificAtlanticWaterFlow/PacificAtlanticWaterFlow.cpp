#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& H) {
        const int N(H.size());
        const int M(H[0].size());

        vector<vector<int>> state(N, vector<int>(M, 0));
        array<int, 5> dk = {1,0,-1,0,1};

        function<void(int, int, int)> dfs;
        dfs = [&](int i, int j, int v) {
            if ((state[i][j] >> v) != 0) return;
            state[i][j] |= 1 << v;

            for (int k = 0; k < 4; ++k) {
                int ii = i + dk[k];
                int jj = j + dk[k + 1];

                if (ii >= 0 && ii < N && jj >= 0 && jj < M
                    && H[ii][jj] >= H[i][j]) dfs(ii, jj, v);
            }
        };

        for (int j = 0; j < M; ++j) dfs(0, j, 0);
        for (int i = 1; i < N; ++i) dfs(i, 0, 0);

        for (int i = 0; i < N; ++i) dfs(i, M - 1, 1);
        for (int j = 0; j < M; ++j) dfs(N - 1, j, 1);

        vector<vector<int>> res;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (state[i][j] == 3) res.push_back({i, j});
            }
        }

        return res;
    }
};