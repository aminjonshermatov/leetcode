#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    using ll = long long;
    static constexpr ll MOD = 1e9 + 7;

    ll gcd(ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
        return a * b / gcd(a, b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        // n = k/a + k/b - k/(lcm(a, b))

        ll l = 1, r = 1e17;
        ll lcmab = lcm(a, b);

        while (l < r) {
            ll mid = (l + r) / 2;
            ll target = (mid / a) + (mid / b) - (mid / lcmab);

            if (target < n) l = mid + 1;
            else r = mid;
        }

        return r % MOD;
    }
};