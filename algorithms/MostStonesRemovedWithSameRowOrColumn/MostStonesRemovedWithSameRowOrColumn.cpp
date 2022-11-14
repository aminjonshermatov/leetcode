#include "bits/stdc++.h"

using namespace std;

class Solution {
    class dsu {
        vector<int> parent, rank;
    public:
        explicit dsu(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            rank.assign(n, 0);
        }

        auto find(int p) -> int {
            if (parent[p] == p) return p;
            return parent[p] = find(parent[p]);
        }

        auto merge(int a, int b) {
            int pa = find(a);
            int pb = find(b);

            if (pa != pb) {
                if (rank[pa] < rank[pb]) swap(pa, pb);
                parent[pb] = pa;
                if (rank[pa] == rank[pb]) ++rank[pa];
            }
        }
    };

public:
    int removeStones(vector<vector<int>>& stones) {
        const auto N = (int)stones.size();

        dsu dsu_(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    dsu_.merge(i, j);
                }
            }
        }

        set<int> uniq;
        for (int i = 0; i < N; ++i) uniq.insert(dsu_.find(i));

        return N - uniq.size();
    }
};