#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (const auto &con : connections) {
            adj[con[0]].emplace_back(con[1], 1);
            adj[con[1]].emplace_back(con[0], 0);
        }

        vector<bool> visited(n, false);
        const function<int(const int)> dfs = [&](const int root) -> int {
            int res = 0;
            visited[root] = true;

            for (const auto [node, same] : adj[root]) {
                if (visited[node]) continue;

                res += same + dfs(node);
            }

            return res;
        };

        return dfs(0);
    }
};