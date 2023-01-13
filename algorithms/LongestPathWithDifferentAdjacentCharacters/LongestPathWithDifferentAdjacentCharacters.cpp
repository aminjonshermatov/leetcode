#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        const int n(parent.size());
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) g[parent[i]].emplace_back(i);

        int ans = 1;
        auto dfs = [&](auto f, int v) -> int {
            int mx1 = 0, mx2 = 0;
            for (auto u : g[v]) {
                auto x = f(f, u);
                if (s[v] == s[u]) continue;
                if (x > mx2) mx2 = x;
                if (mx1 < mx2) swap(mx1, mx2);
            }
            ans = max(ans, mx1 + mx2 + 1);
            return mx1 + 1;
        };
        dfs(dfs, 0);
        return ans;
    }
};