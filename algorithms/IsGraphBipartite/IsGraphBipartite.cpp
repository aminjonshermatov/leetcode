#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = static_cast<int>(graph.size());

        vector<int> group(n, -1);

        const function<bool(const int, const int)> dfs = [&](const int node, const int g) -> bool {
            if (group[node] == -1) {
                group[node] = g;
            } else {
                return group[node] == g;
            }

            for (const auto adjNode : graph[node]) {
                if (not dfs(adjNode, (g + 1) & 1)) return false;
            }

            return true;
        };

        for (int i = 0; i < n; ++i) {
            if (group[i] == -1 and not dfs(i, 0)) return false;
        }

        return true;
    }
};