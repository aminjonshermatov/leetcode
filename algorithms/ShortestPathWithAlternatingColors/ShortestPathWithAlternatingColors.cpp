#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (const auto &edge : redEdges) adj[edge[0]].emplace_back(edge[1], 0);
        for (const auto &edge : blueEdges) adj[edge[0]].emplace_back(edge[1], 1);

        vector<vector<int>> dist(2, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        dist[0][0] = 0;
        dist[1][0] = 0;

        while (not q.empty()) {
            auto [curN, curC] = q.front(); q.pop();

            for (const auto [node, color] : adj[curN]) {
                if (color == curC) continue;

                if (dist[color][node] != INT_MAX) continue;
                dist[color][node] = dist[curC][curN] + 1;
                q.push({node, color});
            }
        }

        vector<int> res(n);

        for (int i = 0; i < n; ++i) {
            auto minEl{min(dist[0][i], dist[1][i])};

            res[i] = minEl == INT_MAX ? -1 : minEl;
        }

        return res;
    }
};