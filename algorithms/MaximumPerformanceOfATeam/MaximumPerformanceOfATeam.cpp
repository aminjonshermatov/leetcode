#include "bits/stdc++.h"

using namespace std;

class Solution {
    inline static constexpr int MOD = 1e9 + 7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        vector<pair<int, int>> es(n);
        for (int i = 0; i < n; ++i) es[i] = make_pair(efficiency[i], speed[i]);
        sort(es.begin(), es.end());

        int64_t ans = 0, sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += es[i].second;
            pq.push(es[i].second);

            if (pq.size() > k) {
                sum -= pq.top(); pq.pop();
            }

            ans = max(ans, es[i].first * sum);
        }

        return static_cast<int>(ans % MOD);
    }
};
