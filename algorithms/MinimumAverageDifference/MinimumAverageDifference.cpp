#include "bits/stdc++.h"

using namespace std;

class Solution {
    static inline constexpr int inf = numeric_limits<int>::max();
    using ll = long long;
public:
    int minimumAverageDifference(vector<int>& nums) {
        const int n(nums.size());
        vector<ll> pf(n + 1, 0);
        for (int i = 0; i < n; ++i) pf[i + 1] = ll(pf[i]) + nums[i];

        pair<int, int> ans{inf, -1};
        for (int i = 0; i < n; ++i) {
            int l = pf[i + 1] / (i + 1);
            int r = (pf[n] - pf[i + 1]) / (i + 1 == n ? inf : n - i - 1);
            if (int abs_ = abs(l - r); abs_ < ans.first) ans = {abs_, i};
        }

        return ans.second;
    }
};