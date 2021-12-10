#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    using ll = long long;
    vector<vector<ll>> dp_;
    static constexpr ll MOD = 1e9 + 7;
    int n_;

    int numTilings(int n) {
        dp_.assign(n, vector<ll>(4, -1));
        n_ = n;
        return static_cast<int>(calc(0, true, true));
    }

    static inline int getState(bool row1, bool row2) {
        int state = 0;
        if (row1) state |= 0b01;
        if (row2) state |= 0b10;
        return state;
    }

    ll calc(ll idx, bool t1, bool t2) {
        if (idx == n_) return 1;

        int state = getState(t1, t2);
        if (dp_[idx][state] != -1) return dp_[idx][state];

        ll count = 0;
        bool t3 = idx + 1 < n_, t4 = t3;

        if (t1 && t2  && t3) count += calc(idx + 1, false, true);
        if (t1 && t2 && t4) count += calc(idx + 1, true, false);
        if (t1 && !t2 && t3 && t4) count += calc(idx + 1, false, false);
        if (!t1 && t2 && t3 && t4) count += calc(idx + 1, false, false);
        if (t1 && t2) count += calc(idx + 1, true, true);
        if (t1 && t2 && t3 && t4) count += calc(idx + 1, false, false);
        if (t1 && !t2 && t3) count += calc(idx + 1, false, true);
        if (!t1 && t2 && t4) count += calc(idx + 1, true, false);
        if (!t1 && !t2) count += calc(idx + 1, true, true);

        return dp_[idx][state] = count % MOD;
    }
};