#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        function<bool(int)> can_reach = [&](int v) {
            double h_ = 0.;

            for (int i = 0; i < dist.size(); ++i) {
                double h = (0. + dist[i]) / v;
                if (i != dist.size() - 1 && dist[i] % v != 0) h = ceil(h);
                h_ += h;
            }

            return h_ <= hour;
        };

        int lo = 1, hi = INT_MAX;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (can_reach(mid)) hi = mid;
            else lo = mid + 1;
        }

        // cout << lo << ' ' << hi << '\n';
        return lo == INT_MAX ? -1 : lo;
    }
};