#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& ps) {
        sort(ps.begin(), ps.end(), [&](const auto &lhs, const auto &rhs) {
            return pair(lhs[1], lhs[0]) < pair(rhs[1], rhs[0]);
        });
        map<int, int> dp{};
        for (auto &p : ps) {
            int mx = 0;
            for (auto [k, v] : dp) {
                if (k < p[0]) {
                    mx = max(mx, v);
                }
            }
            dp[p[1]] = max(dp[p[1]], mx + 1);
        }
        int ans = 0;
        for (auto [_, v] : dp) {
            ans = max(ans, v);
        }
        return ans;
    }
};