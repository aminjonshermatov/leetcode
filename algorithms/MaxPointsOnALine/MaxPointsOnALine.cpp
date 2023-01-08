#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& ps) {
        using seg_t = tuple<int, int, int>;
        map<seg_t, int> fr{};
        const int n(ps.size());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = ps[i][1] - ps[j][1];
                int b = ps[j][0] - ps[i][0];
                int c = -a*ps[i][0] -b*ps[i][1];
                int g = __gcd(a, __gcd(b, c));
                ++fr[make_tuple(a/g, b/g, c/g)];
            }
        }

        pair<int, seg_t> mx{0, {}};
        for (auto &[s, c] : fr) {
            if (c > mx.first) mx = make_pair(c, s);
        }

        int ans = 0;
        for (auto &p : ps) {
            ans += (p[0]*get<0>(mx.second) + p[1]*get<1>(mx.second) + get<2>(mx.second) == 0);
        }
        return ans;
    }
};