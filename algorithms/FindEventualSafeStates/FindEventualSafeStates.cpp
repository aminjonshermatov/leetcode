#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = static_cast<int>(graph.size());

        vector<int> isSafe(n, -1);

        const function<bool(const int)> dfs = [&](const int idx) -> bool {
            if (isSafe[idx] != -1) return static_cast<bool>(isSafe[idx]);

            bool res = true;
            isSafe[idx] = 0;
            if (not graph[idx].empty()) {
                for (int i = 0; i < graph[idx].size() and res; ++i) {
                    res = dfs(graph[idx][i]);
                }
            }

            return isSafe[idx] = res;
        };

        vector<int> res;

        for (int i = 0; i < n; ++i) {
            if (dfs(i)) res.push_back(i);
        }

        return res;
    }
};