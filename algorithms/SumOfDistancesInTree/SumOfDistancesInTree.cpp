#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);

        for (auto &e: edges) g[e[0]].emplace_back(e[1]), g[e[1]].emplace_back(e[0]);

        vector<int> cnt(n, 0), res(n, 0);
        auto dfs1 = [&](auto self, int v, int p) -> void {
            cnt[v] = 1;
            for (auto u: g[v]) if (u != p) {
                    self(self, u, v);
                    cnt[v] += cnt[u];
                    res[v] += cnt[u] + res[u];
                }
        };
        dfs1(dfs1, 0, -1);

        auto dfs2 = [&](auto self, int v, int p) -> void {
            for (auto u: g[v]) if (p != u) {
                    res[u] = res[v] - cnt[u] + n - cnt[u];
                    self(self, u, v);
                }
        };
        dfs2(dfs2, 0, -1);

        return res;
    }
};