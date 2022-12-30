#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        const int n(g.size());

        vector<bool> used(n, false);
        vector<int> path;
        vector<vector<int>> res;
        auto dfs = [&](auto self, int v) -> void {
            path.emplace_back(v);
            used[v] = true;
            if (v == n - 1) {
                res.emplace_back(path);
                path.pop_back();
                used[v] = false;
                return;
            }
            for (auto u : g[v]) if (!used[u]) self(self, u);
            path.pop_back();
            used[v] = false;
        };

        dfs(dfs, 0);
        return res;
    }
};