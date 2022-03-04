#include "bits/stdc++.h"

using namespace std;

class UnionFind {
    vector<int> parent, rank;
    int n;

public:
    UnionFind(int n_) : n{n_} {
        parent.resize(n_);
        for (int i = 0; i < n_; ++i) parent[i] = i;

        rank.resize(n_, 0);
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int   r = static_cast<int>(isConnected.size()),
                    c = static_cast<int>(isConnected[0].size());

        queue<int> q;
        int count = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (isConnected[i][j] == 1) {
                    if (q.empty()) ++count;
                    isConnected[i][j] = 0;
                    q.push(j);
                }
            }

            while (not q.empty()) {
                auto y = q.front(); q.pop();

                for (int j = 0; j < c; ++j) {
                    if (isConnected[y][j] == 1) {
                        q.push(j);
                        isConnected[y][j] = 0;
                    }
                }
            }
        }

        return count;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = static_cast<int>(isConnected.size());

        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    uf.union_(i, j);
                }
            }
        }

        return uf.size();
    }
};