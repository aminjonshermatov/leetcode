#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> cur{0};

        backtrack(graph, cur, 0);

        return res;
    }

    void backtrack(vector<vector<int>>& graph, vector<int>& cur, int idx) {
        if (idx >= graph.size()) return;
        if (!cur.empty() && cur.back() == graph.size() - 1) {
            res.push_back(cur);
            return;
        }

        for (const auto& v : graph[idx]) {
            cur.push_back(v);
            backtrack(graph, cur, v);
            cur.pop_back();
        }
    }
};