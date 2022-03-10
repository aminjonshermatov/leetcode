#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(n, 0));
        vector<int> rank(n, 0);

        for (const auto road : roads) {
            adj[road[0]][road[1]] = adj[road[1]][road[0]] = 1;
            ++rank[road[0]];
            ++rank[road[1]];
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                res = max(res, rank[i] + rank[j] - adj[i][j]);
            }
        }

        return res;
    }
};