#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int n(tasks.size());

        vector<int> A(n);
        iota(A.begin(), A.end(), 0);
        sort(A.begin(), A.end(), [&](auto &lhs, auto &rhs) {
            return tasks[lhs][0] < tasks[rhs][0] || (tasks[lhs][0] == tasks[rhs][0] && tasks[lhs][1] < tasks[rhs][1]);
        });

        vector<int> res;
        res.reserve(n);

        priority_queue<pair<int, int>> pq;
        for (int64_t i = 0, t = 1; i < n || !pq.empty();) {
            for (; i < n && tasks[A[i]][0] <= t; ++i) pq.emplace(-tasks[A[i]][1], -A[i]);
            if (!pq.empty()) {
                auto [tt, ii] = pq.top(); pq.pop();
                t -= tt;
                res.emplace_back(-ii);
            } else {
                t = tasks[A[i]][0];
            }
        }

        return res;
    }
};