#include "bits/stdc++.h"

using namespace std;

class Solution {
    inline static const int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        auto N = arr.size();
        vector<int> dp(N, 1);
        sort(arr.begin(), arr.end());
        map<int, int> uniq;
        for (size_t i = 0; i < N; ++i) uniq[arr[i]] = i;

        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    auto div = arr[i] / arr[j];
                    if (uniq.count(div) > 0) dp[i] = (dp[i] + (uint64_t)dp[j] * dp[uniq[div]]) % MOD;
                }
            }
        }
        int res = 0;
        for (auto num : dp) res += num, res %= MOD;
        return res;
    }
};