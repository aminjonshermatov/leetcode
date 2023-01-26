#include "bits/stdc++.h"

using namespace std;

class Solution {
    static inline constexpr auto inf = numeric_limits<int>::max();
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, inf);
        dist[src] = 0;
        for (int i = 0; i <= k; ++i) {
            auto temp(dist);
            for (auto &f : flights) if (dist[f[0]] != inf) temp[f[1]] = min(temp[f[1]], dist[f[0]] + f[2]);
            dist = temp;
        }
        return dist[dst] == inf ? -1 : dist[dst];
    }
};