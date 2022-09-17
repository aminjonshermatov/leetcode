#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;

        map<int, bool> uniq_v;
        for (const auto &p : adjacentPairs) {
            adj[p[0]].emplace_back(p[1]);
            adj[p[1]].emplace_back(p[0]);

            uniq_v.emplace(p[0], false);
            uniq_v.emplace(p[1], false);
        }

        auto start = -1;
        for (const auto [v, _] : uniq_v) {
            if (adj[v].size() == 1) {
                start = v;
                break;
            }
        }

        queue<int> q;
        uniq_v[start] = true;
        q.push(start);
        vector<int> res;
        res.emplace_back(start);

        while (!q.empty()) {
            auto v = q.front(); q.pop();

            for (auto u : adj[v]) {
                if (!uniq_v[u]) {
                    uniq_v[u] = true;
                    res.emplace_back(u);
                    q.push(u);
                }
            }
        }

        return res;
    }
};