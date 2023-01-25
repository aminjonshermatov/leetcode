#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int n(edges.size());
        array<vector<int>, 2> dist;
        for (int i = 0; i < 2; ++i) dist[i].assign(n, -1);

        auto bfs = [&](auto s, int m) -> void {
            queue<int> q;
            q.emplace(s);
            dist[m][s] = 0;
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                if (edges[u] != -1 && dist[m][edges[u]] == -1) q.emplace(edges[u]), dist[m][edges[u]] = dist[m][u] + 1;
            }
        };
        bfs(node1, 0); bfs(node2, 1);

        auto ans = pair(-1, numeric_limits<int>::max());
        for (int u = 0; u < n; ++u) if (min(dist[0][u], dist[1][u]) >= 0 && max(dist[0][u], dist[1][u]) < ans.second) ans = pair(u, max(dist[0][u], dist[1][u]));
        return ans.first;
    }
};