#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = static_cast<int>(graph.size());

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) {
            for (const auto edge : graph[i]) dist[i][edge] = 1;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX and dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        vector<vector<int>> cache(n, vector<int>(1 << n, -1));
        const function<int(const int, const int)> visit = [&](const int node, const int visited) -> int {
            if (visited == ((1 << n) - 1)) return 0;
            if (cache[node][visited] != -1) return cache[node][visited];

            int best = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if ((visited & (1 << i)) == 0)
                    best = min(best, visit(i, visited | (1 << i)) + dist[node][i]);
            }

            return cache[node][visited] = best;
        };

        int best = INT_MAX;
        for (int i = 0; i < n; ++i) {
            best = min(best, visit(i, 1 << i));
        }

        return best;
    }
};