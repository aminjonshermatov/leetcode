#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }

        int ans = 0;
        auto dfs = [&](auto f, int v, int p) -> bool {
            bool has = hasApple[v];
            for (auto u : g[v]) if (u != p) {
                    auto ok = f(f, u, v);
                    has |= ok;
                    if (ok) ans += 2;
                }
            return has;
        };
        dfs(dfs, 0, -1);

        return ans;
    }
};