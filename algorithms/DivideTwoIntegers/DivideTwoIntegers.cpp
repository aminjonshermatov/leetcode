#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    using ull = uint64_t;
    using ll = int64_t;

    int divide(int dvv, int dss) {
        ull dv = abs(dvv);
        ull ds = abs(dss);
        int sign = ((dvv >= 0) ^ (dss >= 0)) ? -1 : 1;

        ll ans;
        ll lo = 0, hi = 1ull + INT_MAX;
        while (lo <= hi) {
            ll mid = lo + ((hi - lo) >> 1);
            if (mid * ds <= dv) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (sign == 1 && ans > INT_MAX) ans = INT_MAX;
        return min<int>(INT_MAX, max<int>(INT_MIN, ans * sign));
    }
};