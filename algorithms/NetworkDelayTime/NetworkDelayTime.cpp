#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (const auto &t : times) adj[t[0]].emplace_back(t[1], t[2]);

        queue<pair<int, int>> q;
        q.push(make_pair(k, 0));

        vector<int> res(n + 1, INT_MAX);
        res[0] = res[k] = 0;

        while (!q.empty()) {
            auto t{q.front()}; q.pop();

            for (const auto [n_, t_] : adj[t.first]) {
                if (res[n_] > t_ + t.second) {
                    q.push(make_pair(n_, t_ + t.second));
                    res[n_] = t_ + t.second;
                }
            }
        }

        int max_ = *max_element(res.begin(), res.end());
        return max_ == INT_MAX ? -1 : max_;
    }
};