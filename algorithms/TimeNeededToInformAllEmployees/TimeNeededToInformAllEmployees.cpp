#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, unordered_set<int>> adj;

        for (int i = 0; i < n; ++i) adj[manager[i]].insert(i);

        const function<int(const int)> dfs = [&](const int root) -> int {
            if (adj[root].empty()) return 0;

            int temp = 0;
            for (const auto emp : adj[root]) temp = max(temp, dfs(emp));

            return temp + informTime[root];
        };

        return dfs(headID);
    }
};