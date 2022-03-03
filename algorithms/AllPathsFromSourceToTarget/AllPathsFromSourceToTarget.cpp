#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        const int n = static_cast<int>(graph.size());
        vector<vector<int>> res;
        list<int> cur;

        const function<void(const int)> backtrack = [&](const int node) -> void {
            if (node == n - 1) {
                res.emplace_back(cur.begin(), cur.end());
                return;
            }

            for (const auto sibling : graph[node]) {
                cur.push_back(sibling);
                backtrack(sibling);
                cur.pop_back();
            }
        };

        cur.push_back(0);
        backtrack(0);

        return res;
    }
};