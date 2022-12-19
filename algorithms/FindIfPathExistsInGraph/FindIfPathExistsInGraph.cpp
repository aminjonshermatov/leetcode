#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for (auto &e : edges) g[e[0]].emplace_back(e[1]), g[e[1]].emplace_back(e[0]);

        vector<bool> used(n, false);
        queue<int> q;
        q.push(source);
        used[source] = true;
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            if (v == destination) return true;

            for (auto u : g[v]) if (!used[u]) q.push(u), used[u] = true;
        }

        return false;
    }
};