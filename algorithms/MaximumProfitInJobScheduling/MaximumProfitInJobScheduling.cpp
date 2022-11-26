#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& S, vector<int>& E, vector<int>& P) {
        const int n(S.size());

        struct Ev {
            int s, e, p;
            Ev(int s_, int e_, int p_) : s(s_), e(e_), p(p_) { }
        };
        vector<Ev> evs;
        evs.reserve(n);
        map<int, int> comp;
        for (int i = 0; i < n; ++i) evs.emplace_back(S[i], E[i], P[i]), comp[S[i]], comp[E[i]];

        int id = 1;
        for (auto &[_, v] : comp) v = id++;

        sort(evs.begin(), evs.end(), [](Ev &l, Ev &r) { return l.e < r.e; });

        map<int, int> dp;
        dp[0] = 0;
        for (auto [s, e, p] : evs) {
            auto it = prev(dp.upper_bound(comp[s]));
            auto wout = prev(dp.upper_bound(comp[e]));
            dp[comp[e]] = max(wout->second, max(dp[comp[e]], it->second + p));
        }

        int ans = 0;
        for (auto [_, v] : dp) ans = max(ans, v);
        //for (auto [k, v] : comp) cout << k << ' ' << v << '\n';
        //for (auto [k, v] : dp) cout << k << ' ' << v << '\n';

        return ans;
    }
};