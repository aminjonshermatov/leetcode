#include "bits/stdc++.h"

using namespace std;

class UnionFind {
    array<int, 26> p, r;
public:
    UnionFind() {
        fill(r.begin(), r.end(), 1);
        iota(p.begin(), p.end(), 0);
    }

    int find_(int val) {
        if (val != p[val]) p[val] = find_(p[val]);
        return val;
    }

    void union_(int pA, int pB) {
        if (r[pA] > r[pB]) {
            p[pB] = pA;
            ++r[pA];
        } else {
            p[pA] = pB;
            ++r[pB];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;

        for (const auto &eq : equations) {
            if (eq[1] == '=') {
                auto pA = uf.find_(eq[0] - 'a');
                auto pB = uf.find_(eq[3] - 'a');
                uf.union_(pA, pB);
            }
        }

        for (const auto &eq : equations) {
            if (eq[1] == '!') {
                auto pF = uf.find_(eq[0] - 'a');
                auto pS = uf.find_(eq[3] - 'a');
                if (pF == pS) return false;
            }
        }

        return true;
    }
};