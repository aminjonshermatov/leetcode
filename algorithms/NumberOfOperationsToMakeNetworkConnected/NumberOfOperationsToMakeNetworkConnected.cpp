#include "bits/stdc++.h"

using namespace std;

class UnionFind {
    vector<int> parent, rank;
    int n;

public:
    UnionFind(int n_) : n{n_} {
        parent.resize(n_);
        for (int i = 0; i < n_; ++i) parent[i] = i;

        rank.resize(n_);
    }

    auto find_(const int key) -> int {
        if (parent[key] == key) return key;

        return parent[key] = find_(parent[key]);
    }

    auto union_(const int a, const int b) -> void {
        auto pA{find_(a)};
        auto pB{find_(b)};

        if (pA == pB) return;

        if (rank[pA] > rank[pB]) {
            parent[pB] = pA;
            ++rank[pA];
        } else if (rank[pB] > rank[pA]) {
            parent[pA] = pB;
            ++rank[pB];
        } else {
            parent[pA] = pB;
        }
    }

    auto size() -> int const {
        unordered_set<int> uniq;

        for (int i = 0; i < n; ++i) uniq.insert(find_(i));

        return static_cast<int>(uniq.size());
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        const int k = static_cast<int>(connections.size());
        if (k < n - 1) return -1;

        UnionFind uf(n);

        for (const auto connection : connections) uf.union_(connection[0], connection[1]);

        return uf.size() - 1;
    }
};