#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = static_cast<int>(points.size());

        vector<vector<pair<int, int>>> edges(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    edges[i].emplace_back(
                            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]),
                            j
                    );
                }
            }
        }

        int res = 0;
        unordered_set<int> seen;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;

        heap.push({0, 0});
        while (seen.size() < n) {
            auto [minC, curIdx] = heap.top(); heap.pop();

            if (seen.count(curIdx) > 0) continue;

            res += minC;
            seen.insert(curIdx);
            for (const auto [cost, idx] : edges[curIdx]) {
                if (seen.count(idx) == 0) heap.push({cost, idx});
            }
        }

        return res;
    }
};