#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }

        vector<array<int, 26>> dp(n);
        vector<int> res(n);
        auto dfs = [&](auto f, int v, int p) -> void {
            ++dp[v][labels[v] - 'a'];
            for (auto u : g[v]) if (u != p) {
                f(f, u, v);
                for (int ch = 0; ch < 26; ++ch) dp[v][ch] += dp[u][ch];
            }
            res[v] = dp[v][labels[v] - 'a'];
        };
        dfs(dfs, 0, -1);

        return res;
    }
};