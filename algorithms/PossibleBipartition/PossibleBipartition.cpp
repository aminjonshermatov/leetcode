#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n + 1);
        for (auto &e : edges) g[e[0]].emplace_back(e[1]), g[e[1]].emplace_back(e[0]);

        vector<int> color(n + 1, 0);
        auto dfs = [&](auto self, int v, int c) -> bool {
            color[v] = c;
            for (auto u : g[v]) {
                if (color[u] == 0) { if (self(self, u, 3^c)) return true; }
                else if (color[u] != (3^c)) return true;
            }
            return false;
        };

        for (int v = 1; v <= n; ++v) if (color[v] == 0 && dfs(dfs, v, 1)) return false;
        return true;
    }
};