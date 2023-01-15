#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        const int n(vals.size());
        const int m(edges.size());

        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        auto find = [&](auto f, int u) -> int {
            if (p[u] != u) p[u] = f(f, p[u]);
            return p[u];
        };

        sort(edges.begin(), edges.end(), [&](auto &lhs, auto &rhs) {
            return max(vals[lhs[0]], vals[lhs[1]]) < max(vals[rhs[0]], vals[rhs[1]]);
        });

        vector<int> cnt(n, 1);
        int ans = n;
        for (int i = 0; i < m; ++i) {
            auto pu = find(find, edges[i][0]);
            auto pv = find(find, edges[i][1]);

            if (vals[pu] != vals[pv]) {
                if (vals[pu] < vals[pv]) swap(pu, pv);
                p[pv] = pu;
            } else {
                p[pv] = pu;
                ans += cnt[pu] * cnt[pv];
                cnt[pu] += cnt[pv];
            }
        }

        return ans;
    }
};