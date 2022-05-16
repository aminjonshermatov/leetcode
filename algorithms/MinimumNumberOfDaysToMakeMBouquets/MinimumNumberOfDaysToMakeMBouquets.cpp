#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        function<bool(int)> can_make = [&](int d) {
            int c = 0, res = 0;
            for (int i = 0; i < bloomDay.size(); ++i) {
                if (bloomDay[i] <= d) {
                    ++c;
                    if (c == k) ++res, c = 0;
                } else c = 0;
            }

            // cout << d << ' ' << res << '\n';
            return res >= m;
        };

        int mx = *max_element(bloomDay.begin(), bloomDay.end()) + 1;
        int lo = 0, hi = mx;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (can_make(mid)) hi = mid;
            else lo = mid + 1;
        }

        // cout << lo << ' ' << hi << '\n';
        return lo == mx ? -1 : lo;
    }
};