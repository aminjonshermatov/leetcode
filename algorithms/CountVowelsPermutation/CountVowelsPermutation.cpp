#include "bits/stdc++.h"

using namespace std;

class Solution {
    inline static constexpr uint32_t MOD = 1e9 + 7;
    inline static constexpr uint32_t SIZE = 2e4 + 1;

    // a-0,e-1,i-2,o-3,u-4
    inline bool canFollow(uint8_t prev, uint8_t cur) const {
        switch (prev) {
            case 0u: return cur == 1u;
            case 1u: return cur == 0u || cur == 2u;
            case 2u: return cur != 2u;
            case 3u: return cur == 2u || cur == 4u;
            case 4u: return cur == 0u;
            default: return false;
        }
    }

    uint32_t dp[SIZE][5] = {0};

public:
    int countVowelPermutation(int n) {
        for (size_t i = 0; i < 5; ++i) dp[1][i] = 1;

        for (size_t len = 2; len <= n; ++len) {
            for (uint8_t prev = 0; prev < 5; ++prev) {
                for (uint8_t cur = 0; cur < 5; ++cur) {
                    if (canFollow(prev, cur)) dp[len][cur] += dp[len - 1][prev], dp[len][cur] %= MOD;
                }
            }
        }

        uint32_t ans = 0u;
        for (size_t ch = 0; ch < 5; ++ch) ans += dp[n][ch], ans %= MOD;

        return ans;
    }
};