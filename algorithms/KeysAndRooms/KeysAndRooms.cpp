#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n(rooms.size());

        vector<bool> used(n, false);
        queue<int> q;
        q.push(0);
        used[0] = true;

        while (!q.empty()) {
            auto v = q.front(); q.pop();

            for (auto u : rooms[v]) if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                }
        }

        return all_of(used.begin(), used.end(), [](auto b) { return b; });
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n(rooms.size());

        vector<bool> used(n, false);

        auto dfs = [&](const auto self, int v) -> void {
            used[v] = true;
            for (auto u : rooms[v]) if (!used[u]) self(self, u);
        };
        dfs(dfs, 0);

        return all_of(used.begin(), used.end(), [](auto b) { return b; });
    }
};