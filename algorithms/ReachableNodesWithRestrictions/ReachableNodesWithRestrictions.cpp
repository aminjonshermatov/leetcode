#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int, unordered_set<int>> adj;
        unordered_set<int> bad;
        for (auto &e : edges) adj[e[0]].insert(e[1]), adj[e[1]].insert(e[0]);
        for (auto a : restricted) bad.insert(a);

        queue<int> q;
        q.push(0);
        int ans = 0;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            if (bad.count(t) > 0) continue;
            ++ans;
            //cout << t << ' ';
            for (auto a : adj[t])
                if (bad.count(a) == 0) q.push(a);
            bad.insert(t);
        }

        return ans;
    }
};