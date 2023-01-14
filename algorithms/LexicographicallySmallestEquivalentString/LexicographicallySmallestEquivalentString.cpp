#include "bits/stdc++.h"

using namespace std;

class Solution {
    struct Dsu {
        int n;
        vector<int> parent, rank;
        explicit Dsu(int n_) : n(n_), parent(n) {
            iota(parent.begin(), parent.end(), 0);
        }

        auto find(int u) -> int {
            if (parent[u] != u) parent[u] = find(parent[u]);
            return parent[u];
        }

        auto merge(int u, int v) -> void {
            auto pu = find(u);
            auto pv = find(v);

            if (pu == pv) return;
            if (pu > pv) swap(pu, pv);
            parent[pv] = pu;
        }
    };
public:
    string smallestEquivalentString(string s1, string s2, string s3) {
        const int n(s1.size());
        const int m(s3.size());

        Dsu dsu(26);
        for (int i = 0; i < n; ++i) dsu.merge(s1[i] - 'a', s2[i] - 'a');
        auto res = s3;
        for (int i = 0; i < m; ++i) res[i] = char('a' + dsu.find(s3[i] - 'a'));
        return res;
    }
};