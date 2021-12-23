#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        unordered_map<int, unordered_set<int>> adj;
        vector<int> deg(n, 0);

        for (const auto &pp : p) {
            adj[pp[1]].insert(pp[0]);
            ++deg[pp[0]];
        }

        queue<int> q;
        vector<int> res;

        for (int i = 0; i < n; ++i)
            if (deg[i] == 0) q.push(i);

        while (!q.empty()) {
            auto t{q.front()};
            q.pop();

            res.push_back(t);

            for (const auto &el : adj[t]) {
                if (--deg[el] == 0)
                    q.push(el);
            }
        }

        if (res.size() != n) return {};

        return res;
    }
};