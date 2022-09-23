#include "bits/stdc++.h"

using namespace std;

class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        uint64_t res = 0u;
        for (int i = 1; i <= n; ++i) {
            res <<= 32 - __builtin_clz(i);
            res |= i;
            res %= MOD;
        }

        return res;
    }
};