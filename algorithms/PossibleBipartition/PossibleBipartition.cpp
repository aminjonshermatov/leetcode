#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, unordered_set<int>> adj;

        for (const auto dislike : dislikes) {
            adj[dislike[0]].insert(dislike[1]);
            adj[dislike[1]].insert(dislike[0]);
        }

        unordered_map<int, int> group;
        for (int i = 1; i <= n; ++i) group[i] = -1;

        const function<bool(const int, const int)> dfs = [&](const int node, const int g) -> bool {
            if (group[node] == -1) {
                group[node] = g;
            } else {
                return group[node] == g;
            }

            for (const auto adjNode : adj[node]) {
                if (not dfs(adjNode, (g + 1) & 1)) return false;
            }

            return true;
        };

        for (int i = 1; i < n; ++i) {
            if (group[i] == -1 and not dfs(i, 0)) return false;
        }

        return true;
    }
};